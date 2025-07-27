idf_component_register(
    SRCS "main.c"
         "wifi.c"
         "sensor.c"
         "buzzer.c"
         "webserver.c"
    INCLUDE_DIRS "."
    EMBED_TXTFILES "../web/index.html"
)
