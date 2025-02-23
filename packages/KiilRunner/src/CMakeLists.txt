add_definitions(-DTRANSLATION_DOMAIN=\"plasma_runner_org.kde.kiilrunner\")

kcoreaddons_add_plugin(kiilrunner INSTALL_NAMESPACE "kf6/krunner")

target_sources(kiilrunner PRIVATE
    kiilrunner.cpp
)

target_link_libraries(kiilrunner
    Qt6::Gui # QAction
    KF6::Runner
    KF6::I18n
)
