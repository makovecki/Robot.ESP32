
idf_component_register(SRCS "wifi.cpp" "udp.cpp"
                       INCLUDE_DIRS "." "include"
                       PRIV_REQUIRES nvs_flash esp_netif broker
                       )