cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(file-transfer)

# success 链接是 edge 每日一图
file(DOWNLOAD "https://img-prod-cms-rt-microsoft-com.akamaized.net/cms/api/am/imageFileData/RE4wyTs?ver=59ec" "everyday.jpg")

# no test
# file(UPLOAD )