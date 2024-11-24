// AppConfig.h
#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QObject>
#include <QSettings>
#include<QCoreApplication>
#include <QDir>

class AppConfig : public QObject {
    Q_OBJECT

public:
    static AppConfig& instance() {
        static AppConfig instance;
        return instance;
    }

    bool isEnableMica() const { return _isEnableMica; }
    void setIsEnableMica(bool enable) { _isEnableMica = enable; emit configChanged(); }

    bool isEnableTTS() const { return _isEnableTTS; }
    void setIsEnableTTS(bool enable) { _isEnableTTS = enable; emit configChanged(); }

    bool isEnableLogging() const { return _isEnableLogging; }
    void setIsEnableLogging(bool enable) { _isEnableLogging = enable; emit configChanged(); }

    void loadSettings() {
        qDebug() << "正在加载设置数据..";
        QSettings settings(customIniFilePath(),  QSettings::IniFormat);
        _isEnableMica = settings.value("enableMica", false).toBool();
        _isEnableTTS = settings.value("enableTTS", false).toBool();
        _isEnableLogging = settings.value("enableLogging", false).toBool();
    }

    void saveSettings() const {
        QSettings settings(customIniFilePath(),  QSettings::IniFormat);
        settings.setValue("enableMica", _isEnableMica);
        settings.setValue("enableTTS", _isEnableTTS);
        settings.setValue("enableLogging", _isEnableLogging);
    }

signals:
    void configChanged();

private:
    AppConfig() { loadSettings(); }

    QString customIniFilePath() const {
        QString dirPath =  QCoreApplication::applicationDirPath() + "/Config";
        QDir dir;
        qDebug() << "创建路径 "<<dirPath;
        if (!dir.exists(dirPath))
        {
            dir.mkpath(dirPath);
        }
        return dirPath + "/test.ini";
    }


    bool _isEnableMica = false;
    bool _isEnableTTS = true;
    bool _isEnableLogging = false;
};

#endif // APPCONFIG_H
