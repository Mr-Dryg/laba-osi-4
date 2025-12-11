add_library(translation translation.c)
target_link_libraries(translation m)

add_library(realiz_1 SHARED realiz_1.c)
target_link_libraries(realiz_1 translation)

add_library(realiz_2 SHARED realiz_2.c)
target_link_libraries(realiz_2 translation)