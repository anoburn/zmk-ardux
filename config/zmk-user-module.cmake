zephyr_include_directories(${ZMK_PATH}/app/include)

zephyr_library()
zephyr_library_sources(config/custom_naming.c)
