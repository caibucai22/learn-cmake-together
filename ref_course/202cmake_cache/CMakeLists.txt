cmake_minimum_required(VERSION 3.20)
project(cmake_cache)
# 缓存变量 字符串类型
# set(VAR1 "cache var1-1 " CACHE STRING "cache doc")

# 缓存变量第二次修改不生效
# set(VAR1 "cache var1-2 " CACHE STRING "cache doc")


message("VAR1 = ${VAR1}") 

# 强制修改缓存
set(VAR1 "cache var1-1 value1-3 force" CACHE STRING "cache doc" FORCE)

message("VAR1 = ${VAR1}") 


# CACHE 变量作用域是全局的
# 普通变量作用域 自身和子模块

set(VAR_NORMAL "var normal")
message("in main")
message("VAR_NORMAL = ${VAR_NORMAL}")

add_subdirectory(sub1) # 子目录可以获取当前普通变量
add_subdirectory(sub2) # 同级别目录获取不到

message("in main VAR_SUB1 = ${VAR_SUB1}")

message("== in main VAR_CACHE_SUB1 = ${VAR_CACHE_SUB1}")


# 其他类型
# BOOL 勾选
set(VAR_BOOL1 "ON" CACHE BOOL "VAR BOOL 001")
set(VAR_BOOL2 "OFF" CACHE BOOL "VAR bool 002")
message("---------------------------------------------")
message("VAR_BOOL1 = ${VAR_BOOL1}")
message("VAR_BOOL2 = ${VAR_BOOL2}")

# 选择文件
set(VAR_PATH "PATH" CACHE PATH "var path")
# 选择文件夹
set(VAR_FILE "filepath" CACHE FILEPATH "var filepath")

# 内部缓存变量
set(VAR_INTERNAL "INTERNAL" CACHE INTERNAL "var interanl")

# 使用 option 比 使用 set bool 更容易
option(OPT1 "opt1 doc" OFF)
option(OPT1 "opt2 doc" ON)

#普通变量
set(NVAR1 "normal var1")

# 设置缓存变量覆盖同名普通变量的策略
# OLD 删除同名普通变量
# NEW 不删除普通变量，访问cache 要用 $CACHE{var_name}
cmake_policy(SET CMP0126 OLD)
#cache变量
set(NVAR1 "cache var1" CACHE STRING "cache doc")

message("NVAR1 = ${NVAR1}")
message("CACHE{NVAR1} = $CACHE{NVAR1}") # 找cache 中的缓存变量

# -D 传递 -D PARA1=para001 传递缓存变量
message("=============================")
message("PARA1 = ${PARA1}}")
message("=============================")
# -D 和 set 同时存在 -D 会修改掉缓存变量

# 内置
message("BUILD_SHARED_LIBS = ${BUILD_SHARED_LIBS}")