#include <clocale>

#include <QCoreApplication>
#include <QDebug>
#include <QLocale>
#include <QScopedPointer>

#include "utils/utils.hxx"
#include "constants.hxx"


int
main (int argc, char ** argv)
{
  using namespace Constants::Application;


  std::setlocale (LC_ALL, LocaleIdentifier);
  QLocale::setDefault (Locale);

  const QScopedPointer<QCoreApplication> application (
    Utils::makeApplication (argc, argv)
  );

  qDebug () << "Hello";

  QCoreApplication::exit (0);

  return application->exec ();
}
