#include "utils.hxx"

#include <QCoreApplication>

#include "../config/application.hxx"


namespace Utils
{
  QCoreApplication *
  makeApplication (int & argc, char * argv[])
  {
    using namespace Config::Application;


    QCoreApplication * const application (new QCoreApplication (argc, argv));

    QCoreApplication::setApplicationName (Name);
    QCoreApplication::setApplicationVersion (Version);
    QCoreApplication::setOrganizationName (Org_name);
    QCoreApplication::setOrganizationDomain (Org_domain);

    return application;
  }
}
