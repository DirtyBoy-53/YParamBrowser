#include "YParameters.h"
#include <QVariant>
#include <QPair>

#include <QDebug>

using namespace YParamBrowser;

void printDomElement(const QDomElement& element, int indent = 0) {
    // 打印当前元素的名称和属性
    QString indentation = QString(indent, ' ');  // 根据 indent 数量创建缩进
    qDebug() << indentation << "Element: " << element.tagName();

    // 打印当前元素的属性
    QDomNamedNodeMap attributes = element.attributes();
    for (int i = 0; i < attributes.count(); ++i) {
        QDomNode attr = attributes.item(i);
        qDebug() << indentation << "  Attribute: " << attr.nodeName() << "=" << attr.nodeValue();
    }

    // 打印当前元素的文本节点内容（如果有）
    if (!element.text().isEmpty()) {
        qDebug() << indentation << "  Text: " << element.text();
    }

    // 遍历并打印子元素
    QDomElement child = element.firstChildElement();
    while (!child.isNull()) {
        printDomElement(child, indent + 2);  // 递归打印子元素，增加缩进
        child = child.nextSiblingElement();  // 获取下一个兄弟元素
    }
}

// 调用打印函数
void printParam(const QDomElement& param) {
    printDomElement(param);
}

/********************整数类型***********************
 * 类名：YIntParameter
 * 描述：整数类型参数类型
 *
 */


QDomElement YIntParameter::toDom(QDomDocument &doc)
{
    auto param = YParamBase::toDom(doc);
    QDomNode eleRange1 = param.firstChildElement("Range");
    if (!eleRange1.isNull()) {
        param.removeChild(eleRange1);
    }

    // 重新添加范围值（范围是以 "start~end" 格式表示）
    QDomElement eleRange = doc.createElement("Range");
    auto rangePair = vParamRange.value<QPair<int,int>>();
    QDomText txtRange = doc.createTextNode(QString("%1~%2").arg(rangePair.first).arg(rangePair.second));
    param.appendChild(eleRange);
    eleRange.appendChild(txtRange);

    printParam(param);
    return param;
}

bool YIntParameter::fromDom(QDomElement &dom)
{
    auto ret = YParamBase::fromDom(dom);

    // 获取范围值（范围是以 "start~end" 格式表示）
    QDomElement eleRange = dom.firstChildElement("Range");
    if (!eleRange.isNull()) {
        QString rangeText = eleRange.text();
        QStringList rangeParts = rangeText.split("~");
        if (rangeParts.size() == 2) {
            bool ok1, ok2;
            int start = rangeParts[0].toInt(&ok1);
            int end = rangeParts[1].toInt(&ok2);
            if (ok1 && ok2) {
                vParamRange = QVariant::fromValue(QPair<int,int>(start,end));
            } else {
                throw YParamBrowserException(QString("Failed to read 'Range' information:%1").arg(rangeText).toStdString());
            }
        }
    } else {

    }
    return ret;
}

QString YIntParameter::toString()
{
    QString msg = QString("sParamName:%1 vParamValue:%2 sParamRemark:%3 vParamDefault:%4 sParamTip:%5 eParamType:%6 eParamRange:%7")
    .arg(sParamName).arg(vParamValue.toString())
        .arg(sParamRemark).arg(vParamDefault.toString())
        .arg(sParamTip).arg(typeToStr(eParamType))
        .arg(QString::number(vParamRange.value<QPair<int, int>>().first) + "~" +
                           QString::number(vParamRange.value<QPair<int, int>>().second));
    return msg;

}

/********************枚举类型***********************
 * YEnumParameter
 * 描述：枚举类型参数类型
 *
 */

QDomElement YEnumParameter::toDom(QDomDocument &doc)
{
    auto param = YParamBase::toDom(doc);
    QDomNode eleRange1 = param.firstChildElement("Range");
    if (!eleRange1.isNull()) {
        param.removeChild(eleRange1);
    }

    // 重新添加范围值（范围是以 "start~end" 格式表示）
    QDomElement eleRange = doc.createElement("Range");
    auto rangePair = vParamRange.toStringList();
    QDomText txtRange = doc.createTextNode(rangePair.join(','));
    param.appendChild(eleRange);
    eleRange.appendChild(txtRange);

    printParam(param);
    return param;
}

bool YEnumParameter::fromDom(QDomElement &dom)
{
    auto ret = YParamBase::fromDom(dom);

    // 获取范围值（范围是以 "start~end" 格式表示）
    QDomElement eleRange = dom.firstChildElement("Range");
    if (!eleRange.isNull()) {
        QString rangeText = eleRange.text();
        QStringList rangeParts = rangeText.split(",");
        if (rangeParts.size() > 1) {
            vParamRange = QVariant(rangeParts);
        } else {
            throw YParamBrowserException(QString("Failed to read 'Range' information:%1").arg(rangeText).toStdString());
        }
    } else {

    }
    return ret;
}
