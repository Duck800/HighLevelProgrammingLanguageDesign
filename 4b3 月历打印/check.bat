@echo 测试即将开始，用时约一分半钟。^若长时间无反应，请尝试打开echo检查错误。
@echo 友情提示：这个bat是给你检查大量测试数据用的，不应该成为你不练习使用管道和重定向的理由。
@echo 请注意：本次测试不包括错误处理。
@echo off

echo >myresult.txt
echo >demoresult.txt

setlocal enabledelayedexpansion

::你需要改的地方在这里↓
cd "G:\Homework\homework\4b3 月历打印"

set count=0
for /f "delims=^" %%i in (test-data.txt) do (
echo Data #!count! is %%i^ >>myresult.txt
echo %%i^ | my >>myresult.txt
set /a count+=1
)

set count=0

for /f "delims=^" %%i in (test-data.txt) do (
echo Data #!count! is %%i^ >>demoresult.txt
echo %%i^ | demo >>demoresult.txt
set /a count+=1
)

echo on

fc myresult.txt demoresult.txt

@pause