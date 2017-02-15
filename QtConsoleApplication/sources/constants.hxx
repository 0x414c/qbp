#pragma once

#ifndef __QBP_DEFINE_PREFIX_CONFIG_HXX
#define __QBP_DEFINE_PREFIX_CONFIG_HXX


#include <QLocale>
#include <QString>


namespace Constants
{
  namespace Application
  {
    const QString Name (QStringLiteral ("__QBP_APP_NAME"));
    const QString Version (QStringLiteral ("__QBP_APP_VERSION"));
    const QString OrgName (QStringLiteral ("__QBP_ORG_NAME"));
    const QString OrgDomain (QStringLiteral ("__QBP_ORG_DOMAIN"));
    const QString Description (QStringLiteral ("__QBP_APP_DESCRIPTION"));

    // NOTE: Identifier format is: [language[_territory][.codeset][@modifier]]
    constexpr const char * const LocaleIdentifier ("en_US.UTF-8");
    const QLocale Locale (LocaleIdentifier);
  }
}


#endif // __QBP_DEFINE_PREFIX_CONFIG_HXX
