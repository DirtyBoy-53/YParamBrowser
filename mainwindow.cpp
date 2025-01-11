#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QDate>
#include <QDateTime>
#include <QKeySequence>

#include <YParamBase.hpp>
#include "YParamManager.h"
#include "YParamFactory.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
using namespace YParamBrowser;
#if 0
    QVariant va =  QVariant::fromValue(QPair<int,int>(10,100));
    auto rangePair = va.value<QPair<int,int>>();
    qDebug() << QString("%1~%2").arg(rangePair.first).arg(rangePair.second);

    QMetaEnum metaEnum = QMetaEnum::fromType<YParamEnum::ParamType>();

    qDebug() << metaEnum.valueToKey(YParamEnum::ParamType_Bool) <<  QString(metaEnum.valueToKey(100)).isEmpty();

    using baseType = QMap<QString, int>;
    QMap<QString, baseType> testType;
    baseType t1;
    t1["1"] = 1;
    t1["2"] = 2;
    t1["3"] = 3;

    baseType t2;
    t1["11"] = 11;
    t1["22"] = 22;
    t1["33"] = 33;

    testType["t1"] = t1;
    testType["t2"] = t2;
    int value;
    auto name = "11";
    for (auto outerIt = testType.constBegin(); outerIt != testType.constEnd(); ++outerIt) {
        const auto& innerMap = outerIt.value();
        if (innerMap.contains(name)) {
            value = innerMap.value(name);
            qDebug() << "Found key '11' with value:" << value;
            break;
        }
    }
#endif
    YParamManager *manager = new YParamManager();

    QVBoxLayout *layout = new QVBoxLayout(centralWidget());
    YParamPtr param1 = YParamFactory::createParameter(
            YParamEnum::ParamType_Int,
            QVariant(11),
            QVariant(10),
            QVariant::fromValue(QPair<int,int>(0,100)),
            "Test1",
            "Test1_Tips"
        );

    YParamPtr param2 = YParamFactory::createParameter(
            YParamEnum::ParamType_Int,
            QVariant(12),
            QVariant(10),
            QVariant::fromValue(QPair<int,int>(0,100)),
            "Test2",
            "Test2_Tips"
        );

    YParamPtr param3 = YParamFactory::createParameter(
        YParamEnum::ParamType_String,
        QVariant("Hello YParam"),
        QVariant("string"),
        QVariant(),
        "Test3",
        "Test3_Tips"
        );

    YParamPtr param4 = YParamFactory::createParameter(
        YParamEnum::ParamType_Double,
        QVariant(3.1415926),
        QVariant(0.0),
        QVariant(),
        "Test4",
        "Test4_Tips"
        );

    YParamPtr param5 = YParamFactory::createParameter(
        YParamEnum::ParamType_PassWordStr,
        QVariant(12345678),
        QVariant(1),
        QVariant(),
        "Test5",
        "Test5_Tips"
        );

    YParamPtr param6 = YParamFactory::createParameter(
        YParamEnum::ParamType_Enum,
        QVariant(2),
        QVariant(2),
        QVariant(QStringList() << "banana" << "orange" << "apple" << "grape"),
        "Test6",
        "Test6_Tips"
        );

    YParamPtr param7 = YParamFactory::createParameter(
        YParamEnum::ParamType_Bool,
        QVariant(false),
        QVariant(false),
        QVariant(),
        "Test7",
        "Test7_Tips"
        );

    YParamPtr param8 = YParamFactory::createParameter(
        YParamEnum::ParamType_File,
        QVariant("D:/file.txt"),
        QVariant("D:/file.txt"),
        QVariant(),
        "Test8",
        "Test8_Tips"
        );

    YParamPtr param9 = YParamFactory::createParameter(
        YParamEnum::ParamType_Folder,
        QVariant("D:/"),
        QVariant("D:/"),
        QVariant(),
        "Test9",
        "Test9_Tips"
        );

    YParamPtr param10 = YParamFactory::createParameter(
        YParamEnum::ParamType_Date,
        QVariant("2025-01-11"),
        QVariant(QDate::currentDate()),
        QVariant(),
        "Test10",
        "Test10_Tips"
        );

    YParamPtr param11 = YParamFactory::createParameter(
        YParamEnum::ParamType_Time,
        QVariant("15:35:11"),
        QVariant(QTime::currentTime()),
        QVariant(),
        "Test11",
        "Test11_Tips"
        );

    YParamPtr param12 = YParamFactory::createParameter(
        YParamEnum::ParamType_DateTime,
        QVariant("2025-01-11 15:39:52.768"),
        QVariant(QDateTime::currentDateTime()),
        QVariant(),
        "Test12",
        "Test12_Tips"
        );

    YParamPtr param13 = YParamFactory::createParameter(
        YParamEnum::ParamType_KeySeq,
        QVariant("Ctrl+Q"),
        QVariant(QVariant::fromValue(QKeySequence(Qt::ControlModifier | Qt::Key_Q))),
        QVariant(),
        "Test13",
        "Test13_Tips"
        );


    YParamPtr param14 = YParamFactory::createParameter(
        YParamEnum::ParamType_Locale,
        QVariant("zh_CN"),
        QVariant(QLocale(QLocale::Polish, QLocale::Poland)),
        QVariant(),
        "Test14",
        "Test14_Tips"
        );

    YParamPtr param15 = YParamFactory::createParameter(
        YParamEnum::ParamType_Point,
        QVariant(QPoint(1,1)),
        QVariant(QPoint(2,2)),
        QVariant(),
        "Test15",
        "Test15_Tips"
        );

    manager->addParam(param1, "IntParam");
    manager->addParam(param2, "IntParam");
    manager->addParam(param3, "StringParam");
    manager->addParam(param4, "DoubleParam");
    manager->addParam(param5, "PassWordStr");
    manager->addParam(param6, "Enum");
    manager->addParam(param7, "Bool");
    manager->addParam(param8, "File");
    manager->addParam(param9, "Folder");
    manager->addParam(param10, "Date");
    manager->addParam(param11, "Time");
    manager->addParam(param12, "DateTime");
    manager->addParam(param13, "KeySeq");
    manager->addParam(param14, "Locale");
    manager->addParam(param15, "Point");


    manager->layoutAddParamWidget(layout);
    manager->on_update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}
