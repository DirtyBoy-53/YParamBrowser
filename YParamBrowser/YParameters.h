#ifndef YPARAMETERS_HPP
#define YPARAMETERS_HPP
#include "YParamBase.hpp"
#include <QString>

namespace YParamBrowser{

// int parameter
class YIntParameter : public YParamBase{
public:
    YIntParameter() = delete;
    YIntParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Int,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

    // YParamBase interface
public:
    QDomElement toDom(QDomDocument& doc);
    bool fromDom(QDomElement &dom);
    QString toString();
};

// string parameter
class YStringParameter : public YParamBase{
public:
    YStringParameter() = delete;
    YStringParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_String,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

};

// double parameter
class YDoubleParameter : public YParamBase{
public:
    YDoubleParameter() = delete;
    YDoubleParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Double,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

};

// PassWordStr parameter
class YPassWordStrParameter : public YParamBase{
public:
    YPassWordStrParameter() = delete;
    YPassWordStrParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_PassWordStr,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

};

// PassWordStr parameter
class YEnumParameter : public YParamBase{
public:
    YEnumParameter() = delete;
    YEnumParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_PassWordStr,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

    // YParamBase interface
public:

    QDomElement toDom(QDomDocument &doc);
    bool fromDom(QDomElement &dom);
};


// Bool parameter
class YBoolParameter : public YParamBase{
public:
    YBoolParameter() = delete;
    YBoolParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Bool,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

};

// File parameter
class YFileParameter : public YParamBase{
public:
    YFileParameter() = delete;
    YFileParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_File,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }
};

// Folder parameter
class YFolderParameter : public YParamBase{
public:
    YFolderParameter() = delete;
    YFolderParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Folder,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }
};

// Date parameter
class YDateParameter : public YParamBase{
public:
    YDateParameter() = delete;
    YDateParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Date,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }
};

// Time parameter
class YTimeParameter : public YParamBase{
public:
    YTimeParameter() = delete;
    YTimeParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Time,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }
};

// DateTime parameter
class YDateTimeParameter : public YParamBase{
public:
    YDateTimeParameter() = delete;
    YDateTimeParameter(
        const YParamEnum::ParamType&    type    = YParamEnum::ParamType_DateTime,
        const QVariant&                 value   = QVariant(),
        const QVariant&                 defvalue= QVariant(),
        const QVariant&                 range   = QVariant(),
        const QString&                  name    = "name",
        const QString&                  tip     = "tips",
        const QString&                  remark  = "Notes"
        ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }
};

// KeySeq parameter
class YKeySeqParameter : public YParamBase{
public:
    YKeySeqParameter() = delete;
    YKeySeqParameter(
            const YParamEnum::ParamType&    type    = YParamEnum::ParamType_KeySeq,
            const QVariant&                 value   = QVariant(),
            const QVariant&                 defvalue= QVariant(),
            const QVariant&                 range   = QVariant(),
            const QString&                  name    = "name",
            const QString&                  tip     = "tips",
            const QString&                  remark  = "Notes"
            ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }
};

// Locale parameter
class YLocaleParameter : public YParamBase{
public:
    YLocaleParameter() = delete;
    YLocaleParameter(
            const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Locale,
            const QVariant&                 value   = QVariant(),
            const QVariant&                 defvalue= QVariant(),
            const QVariant&                 range   = QVariant(),
            const QString&                  name    = "name",
            const QString&                  tip     = "tips",
            const QString&                  remark  = "Notes"
            ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

    // YParamBase interface
public:
    virtual QDomElement toDom(QDomDocument &doc) override;
    virtual bool fromDom(QDomElement &dom) override;
};

// Point parameter
class YPointParameter : public YParamBase{
public:
    YPointParameter() = delete;
    YPointParameter(
            const YParamEnum::ParamType&    type    = YParamEnum::ParamType_Point,
            const QVariant&                 value   = QVariant(),
            const QVariant&                 defvalue= QVariant(),
            const QVariant&                 range   = QVariant(),
            const QString&                  name    = "name",
            const QString&                  tip     = "tips",
            const QString&                  remark  = "Notes"
            ) : YParamBase(type, value, defvalue, range, name, tip, remark){ }

    // YParamBase interface
public:
    virtual QDomElement toDom(QDomDocument &doc) override;
    virtual bool fromDom(QDomElement &dom) override;
    virtual void setVParamValue(const QVariant &newVParamValue, const QtProperty *property) override;
};

} // namespace YParamBrowser




#endif // YPARAMETERS_HPP
