#include "application.hxx"

#include <QApplication>

#include "../config/application.hxx"


namespace Utils
{
  QApplication *
  makeApplication (int & argc, char * argv[])
  {
    using namespace Config::Application;


    QApplication * const application (new QApplication (argc, argv));

    QCoreApplication::setApplicationName (Name);
    QCoreApplication::setApplicationVersion (Version);
    QCoreApplication::setOrganizationName (Org_name);
    QCoreApplication::setOrganizationDomain (Org_domain);
    QApplication::setApplicationDisplayName (Display_name);

    return application;
  }
}
