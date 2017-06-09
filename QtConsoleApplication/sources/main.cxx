#include <clocale>

#include <QCoreApplication>
#include <QDebug>
#include <QLocale>
#include <QScopedPointer>

#include "config/application.hxx"
#include "utils/utils.hxx"


int
main (int argc, char * argv[])
{
  using namespace Config::Application;


  std::setlocale (LC_ALL, Locale_identifier);
  QLocale::setDefault (Locale);

  const QScopedPointer<QCoreApplication> application (
    Utils::makeApplication (argc, argv)
  );

  qDebug () << "Hello";

  QCoreApplication::exit (0);

  return application->exec ();
}
