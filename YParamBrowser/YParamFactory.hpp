#ifndef YPARAMFACTORY_HPP
#define YPARAMFACTORY_HPP
#include <memory>

#include "YParamBase.hpp"
#include "YParameters.h"
#include <QDebug>

namespace YParamBrowser {

// 名称：参数类型工厂
// 描述：根据参数类型创建参数对象
class YParamFactory
{

public:
    static YParamPtr createParameter(
            const YParamEnum::ParamType&    type,
            const QVariant&                 value   = QVariant(),
            const QVariant&                 defvalue= QVariant(),
            const QVariant&                 range   = QVariant(),
            const QString&                  name    = "name",
            const QString&                  tip     = "tips",
            const QString&                  remark  = "Notes"
        ) {
        switch (type) {
            case YParamEnum::ParamType_Int:
                return std::make_shared<YIntParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_String:
                return std::make_shared<YStringParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_Double:
                return std::make_shared<YDoubleParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_PassWordStr:
                return std::make_shared<YPassWordStrParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_Enum:
                return std::make_shared<YEnumParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_Bool:
                return std::make_shared<YBoolParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_File:
                return std::make_shared<YFileParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_Folder:
                return std::make_shared<YFolderParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            case YParamEnum::ParamType::ParamType_Date:
                return std::make_shared<YDateParameter>(type, value, defvalue, range, name, tip, remark);
                break;
            default:
                return nullptr;
        }
            return nullptr;
    }


    static YParamPtr createParameter(const QString& str){
        YParamEnum::ParamType type = YParamBase::strToType(str);
        switch (type) {
        case YParamEnum::ParamType_Int:
            return std::make_shared<YIntParameter>(type);
            break;
        case YParamEnum::ParamType::ParamType_Double:
            return std::make_shared<YDoubleParameter>(type);
            break;
        case YParamEnum::ParamType_String:
            return std::make_shared<YStringParameter>(type);
            break;
        case YParamEnum::ParamType::ParamType_PassWordStr:
            return std::make_shared<YPassWordStrParameter>(type);
            break;
        case YParamEnum::ParamType::ParamType_Enum:
            return std::make_shared<YEnumParameter>(type);
            break;
        case YParamEnum::ParamType::ParamType_Bool:
            return std::make_shared<YBoolParameter>(type);
            break;
        case YParamEnum::ParamType::ParamType_File:
            return std::make_shared<YFileParameter>(type);
            break;
        case YParamEnum::ParamType::ParamType_Folder:
            return std::make_shared<YFolderParameter>(type);
            break;
        case YParamEnum::ParamType::ParamType_Date:
            return std::make_shared<YDateParameter>(type);
            break;
        default:
            return nullptr;
        }
    }

};

} // namespace YParamBrowser


#endif // YPARAMFACTORY_HPP
