
idf_component_register(SRCS "broker.cpp" "processor.cpp"
                       INCLUDE_DIRS "." "include"
                       PRIV_REQUIRES nvs_flash 
                       )