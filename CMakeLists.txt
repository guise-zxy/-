idf_component_register(SRCS "main.c"
                        "SHT31.c"
                    INCLUDE_DIRS "."
                     REQUIRES esp_driver_i2c
        
                    )
