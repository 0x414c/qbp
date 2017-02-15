#include <clocale>

#include <QApplication>
#include <QLocale>
#include <QScopedPointer>

#include "utils/application.hxx"
#include "widgets/mainwindow.hxx"
#include "constants.hxx"


int
main (int argc, char ** argv)
{
  using namespace Constants::Application;


  std::setlocale (LC_ALL, LocaleIdentifier);
  QLocale::setDefault (Locale);

  QApplication::setDesktopSettingsAware (IsDesktopSettingsAware);

  const QScopedPointer<QApplication> application (
    Utils::makeApplication (argc, argv)
  );

  Widgets::MainWindow mainWindow;
  mainWindow.show ();

  return application->exec ();
}
