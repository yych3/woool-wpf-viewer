# 定义解决方案文件的名称
SOLUTION = WpfFileViewer.sln

# 定义 MSBuild 的路径，通常在 Windows 系统中可以通过环境变量调用
MSBUILD = msbuild

# 定义编译配置，这里使用 Release 模式
CONFIGURATION = Release

# 默认目标，执行编译操作
all: build

# 编译解决方案
build:
    $(MSBUILD) $(SOLUTION) /p:Configuration=$(CONFIGURATION)
     echo "Compiled files are in: $(shell dir bin/Release)"

# 重新编译，先清理再编译
rebuild: clean build
