#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVBoxLayout>

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
        QVariant("None"),
        "Test3",
        "Test3_Tips"
        );

    YParamPtr param4 = YParamFactory::createParameter(
        YParamEnum::ParamType_Double,
        QVariant(3.1415926),
        QVariant(0.0),
        QVariant("None"),
        "Test4",
        "Test4_Tips"
        );

    YParamPtr param5 = YParamFactory::createParameter(
        YParamEnum::ParamType_PassWordStr,
        QVariant(12345678),
        QVariant(1),
        QVariant("None"),
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
        QVariant("None"),
        "Test7",
        "Test7_Tips"
        );

    YParamPtr param8 = YParamFactory::createParameter(
        YParamEnum::ParamType_File,
        QVariant("D:/file.txt"),
        QVariant("D:/file.txt"),
        QVariant("None"),
        "Test8",
        "Test8_Tips"
        );

    YParamPtr param9 = YParamFactory::createParameter(
        YParamEnum::ParamType_Folder,
        QVariant("D:/"),
        QVariant("D:/"),
        QVariant("None"),
        "Test9",
        "Test9_Tips"
        );

    YParamPtr param10 = YParamFactory::createParameter(
        YParamEnum::ParamType_Date,
        QVariant("2025-1-11"),
        QVariant("2025-1-11"),
        QVariant("None"),
        "Test10",
        "Test10_Tips"
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


    manager->layoutAddParamWidget(layout);
    manager->on_update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}
