cmake_minimum_required(VERSION 3.16)

# Point to your ESP-IDF
set(IDF_PATH $ENV{IDF_PATH})

# Create spiffs image from web/ folder
#   storage = partition name in partitions.csv
spiffs_create_partition_image(storage ${CMAKE_SOURCE_DIR}/web FLASH_IN_PROJECT)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(fire-smoke-alert)
