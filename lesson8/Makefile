# 扫描当前目录所有 .c 源文件
SRC = $(wildcard *.c)
# 每个 .c 对应一个同名可执行文件（去掉.c后缀）
BINS = $(SRC:.c=)

# 默认目标：编译所有程序
all: $(BINS)

# 模式规则：任意可执行文件 依赖同名 .c 文件
% : %.c
	gcc $< -o $@

# 清理：删除所有可执行文件和 .o 中间文件
.PHONY: clean
clean:
	rm -f $(BINS) *.o

