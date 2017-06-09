#include <clocale>

#include <QApplication>
#include <QLocale>
#include <QScopedPointer>

#include "config/application.hxx"
#include "utils/application.hxx"
#include "widgets/main-window.hxx"


int
main (int argc, char * argv[])
{
  using namespace Config::Application;


  std::setlocale (LC_ALL, Locale_identifier);
  QLocale::setDefault (Locale);

  QApplication::setDesktopSettingsAware (Is_desktop_settings_aware);

  const QScopedPointer<QApplication> application (
    Utils::makeApplication (argc, argv)
  );

  Widgets::MainWindow main_window;
  main_window.show ();

  return application->exec ();
}
