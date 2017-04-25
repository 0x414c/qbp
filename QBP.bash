#!/usr/bin/env bash

generator_name='QBP'

question_prompt='??? '
output_prompt='>>> '

widgets_template='QtWidgetsApplication'
console_template='QtConsoleApplication'

default_app_type='w'

default_app_name='MyApplication'
default_app_description='My Qt Application'
default_app_version='0.0.1'
default_app_copyright='Copyright (C) 2016  John Doe'
default_target_name='myapplication'
default_org_name='JohnDoe'
default_org_domain='www.example.com'
default_macro_prefix='MYAPP'
breeze_icons_version='5.25.0-rc1'

while true; do
    read -p "${question_prompt} Application type: (\`w' for widgets, \`c' for console; default \`${default_app_type}'): " app_type
    read -p "${question_prompt} Application name: (default \`${default_app_name}'): " app_name
    read -p "${question_prompt} Application description (default \`${default_app_description}'): " app_description
    read -p "${question_prompt} Application version (default \`${default_app_version}'): " app_version
    read -p "${question_prompt} Application copyright (default \`${default_app_copyright}'): " app_copyright
    read -p "${question_prompt} Executable name (default \`${default_target_name}'): " target_name
    read -p "${question_prompt} Organisation name (default \`${default_org_name}'): " org_name
    read -p "${question_prompt} Organisation domain (default \`${default_org_domain}'): " org_domain
    read -p "${question_prompt} Prefix for macros (default \`${default_macro_prefix}'): " macro_prefix

    app_type="${app_type:-${default_app_type}}"
    app_name="${app_name:-${default_app_name}}"
    app_description="${app_description:-${default_app_description}}"
    app_version="${app_version:-${default_app_version}}"
    app_copyright="${app_copyright:-${default_app_copyright}}"
    target_name="${target_name:-${default_target_name}}"
    org_name="${org_name:-${default_org_name}}"
    org_domain="${org_domain:-${default_org_domain}}"
    macro_prefix="${macro_prefix:-${default_macro_prefix}}"

    echo "${output_prompt} Going to create application template using this information:"
    echo "${output_prompt} Type: \`${app_type}'"
    echo "${output_prompt} Name: \`${app_name}'"
    echo "${output_prompt} Description: \`${app_description}'"
    echo "${output_prompt} Version: \`${app_version}'"
    echo "${output_prompt} Copyright: \`${app_copyright}'"
    echo "${output_prompt} Executable: \`${target_name}'"
    echo "${output_prompt} Organisation: \`${org_name}'"
    echo "${output_prompt} Organisation domain: \`${org_domain}'"
    echo "${output_prompt} Prefix for macros: \`${macro_prefix}'"

    read -p "${question_prompt} Is this right for you (if you want to fix something, answer \`no') (default \`yes')? " is_ok

    is_ok="${is_ok:-yes}"

    case "${is_ok}" in
        [yY] | [yY][eE][sS] )
            echo "${output_prompt} Okay, generating project template now..."

            creation_time="$(date --iso-8601='seconds')"

                case "${app_type}" in
                    [wW] )
                        template="${widgets_template}"
                        ;;

                    [cC] )
                        template="${console_template}"
                        ;;
                esac

            cp -Riv "./${template}/" "./${app_name}/"

            cd "./${app_name}/"

            find './' -type f \( -name '*.cxx' -or -name '*.hxx' -or -name '*.pro' \) -exec \
                sed -i \
                    -e "s/__QBP_APP_NAME__/${app_name}/g" \
                    -e "s/__QBP_APP_DESCRIPTION__/${app_description}/g" \
                    -e "s/__QBP_APP_VERSION__/${app_version}/g" \
                    -e "s/__QBP_APP_COPYRIGHT__/${app_copyright}/g" \
                    -e "s/__QBP_ORG_NAME__/${org_name}/g" \
                    -e "s/__QBP_ORG_DOMAIN__/${org_domain}/g" \
                    -e "s/__QBP_DEFINE_PREFIX__/${macro_prefix}/g" \
                    -e "s/__QBP_BREEZE_ICONS_VERSION__/${breeze_icons_version}/g" \
                    -e "s/__QBP_GENERATOR_NAME__/${generator_name}/g" \
                    -e "s/__QBP_CREATION_TIME__/${creation_time}/g" \
                    -e "s/__QBP_TARGET_NAME__/${target_name}/g" \
                    -e "s/__QBP_WIN32_TARGET_VERSION__/${app_version}.0/g" \
                    -e "s/__QBP_TARGET_VERSION__/${app_version}/g" \
                    -e "s/__QBP_QMAKE_TARGET_COMPANY__/${org_name}/g" \
                    -e "s/__QBP_QMAKE_TARGET_PRODUCT__/${app_name}/g" \
                    -e "s/__QBP_QMAKE_TARGET_DESCRIPTION__/${app_description}/g" \
                    -e "s/__QBP_QMAKE_TARGET_COPYRIGHT__/${app_copyright}/g" \
                    {} +

            # rm -iv "./${template}.pro.user"
            mv -iv "./${template}.pro.user" "./${app_name}.pro.user"

            mv -iv "./${template}.pro" "./${app_name}.pro"

            echo "${output_prompt} Done generating application template in directory \`${app_name}'."

            break
            ;;

        [nN] | [nN][oO] )
            echo "${output_prompt} Restarting..."
            ;;
    esac
done

## EOF
