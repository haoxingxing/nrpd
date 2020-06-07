cmake_minimum_required (VERSION 3.8)

aux_source_directory(. src)
add_executable (nrpd ${src} "v1/Handler.h" "v1/Handler.cpp" "v1/plastebin.h" "v1/plastebin.cpp")
set_target_properties(nrpd PROPERTIES DEBUG_POSTFIX "d") 
set_target_properties(nrpd PROPERTIES OUTPUT_NAME "nrpd.${FILENAME_SUFFIX}")
if (UNIX)
	TARGET_LINK_LIBRARIES(nrpd dl)
endif()
link_directories(${OUTDIR})


# TODO: 如有需要，请添加测试并安装目标。
