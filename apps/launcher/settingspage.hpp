#ifndef SETTINGSPAGE_HPP
#define SETTINGSPAGE_HPP

#include <QWidget>
#include <QProcess>

#include <components/process/processinvoker.hpp>

#include "ui_settingspage.h"

#include "maindialog.hpp"

namespace Config { class GameSettings;
                   class LauncherSettings; }

namespace Launcher
{
    class TextInputDialog;

    class SettingsPage : public QWidget, private Ui::SettingsPage
    {
        Q_OBJECT

    public:
        SettingsPage( Config::GameSettings &gameSettings,
                      Config::LauncherSettings &launcherSettings, MainDialog *parent = 0);

        void saveSettings();
        bool loadSettings();

    private slots:
        void on_wizardButton_clicked();
        void on_importerButton_clicked();

        void wizardStarted();
        void wizardFinished(int exitCode, QProcess::ExitStatus exitStatus);

        void importerStarted();
        void importerFinished(int exitCode, QProcess::ExitStatus exitStatus);

        void updateOkButton(const QString &text);

    private:
        Process::ProcessInvoker *mWizardInvoker;
        Process::ProcessInvoker *mImporterInvoker;

        Config::GameSettings &mGameSettings;
        Config::LauncherSettings &mLauncherSettings;

        MainDialog *mMain;
        TextInputDialog *mProfileDialog;


    };
}

#endif // SETTINGSPAGE_HPP
