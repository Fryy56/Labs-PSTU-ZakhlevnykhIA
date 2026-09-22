if (${LAB_NUM} EQUAL 0)
    set(LABS_INCLUDE_DIRS
        src
    )
else()
    set(LABS_INCLUDE_DIRS "")
endif()

list(TRANSFORM LABS_INCLUDE_DIRS PREPEND "bachelor/sem1/informatics/lab${LAB_NUM}/")
list(JOIN LABS_INCLUDE_DIRS " " LABS_INCLUDE_STR)

if ("${LABS_INCLUDE_STR}" MATCHES "^$")
    message(STATUS "No include dirs provided")
else()
    message(STATUS "Include dirs: ${LABS_INCLUDE_STR}")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    ${LABS_INCLUDE_STR}
)