# 502install_file/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)

project(install_file)

file(WRITE a.h "")
file(WRITE b.h "")

# 文件安装到指定目录
install(FILES a.h b.h DESTINATION include)

# 不存在 不报错， 目标可选 
install(FILES c.h DESTINATION inc OPTIONAL)

# 文件类型 TYPE DOC LIB INCLUDE
include(GNUInstallDirs) # 引入后 才能使用CMAKE_INSTALL_DATAROOTDIR
message("{CMAKE_INSTALL_DATAROOTDIR}")
install(FILES a.h TYPE DOC) # dataroot_dir /doc
install(FILES b.h TYPE LIB) # lib
install(FILES c.h TYPE INCLUDE) # include


# 文件权限  windows 目录无效
# 默认权限 OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ
install(FILES a.h DESTINATION pub
PERMISSIONS
OWNER_WRITE OWNER_READ OWNER_EXECUTE
GROUP_READ GROUP_WRITE GROUP_EXECUTE
WORLD_READ WORLD_WRITE WORLD_EXECUTE
)


