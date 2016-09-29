
CC=gcc
CPPFLAGS=-I./include -I /usr/local/include/hiredis/ 
CFLAGS=-Wall 
LIBS= -lhiredis

#找到当前目录下所有的.c文件
src = $(wildcard *.c)

#将当前目录下所有的.c  转换成.o给obj
obj = $(patsubst %.c, %.o, $(src))



#upload=cgi_bin/upload
#data=cgi_bin/data
#reg=cgi_bin/reg
#login=cgi_bin/login

#fdfs_file_info_test=test/fdfs_file_info_test
fdfs_client_test = ./test/test_fdfs_client
main = main_test
redis_test = redis_test

target=$(fdfs_client_test) $(main) $(redis_test)


ALL:$(target)


#生成所有的.o文件
$(obj):%.o:%.c
	$(CC) -c $< -o $@ $(CPPFLAGS) $(CFLAGS) 


#fdfs_client_test程序
$(fdfs_client_test):./test/fdfs_client_test.o make_log.o
	$(CC) $^ -o $@ $(LIBS)

#main_test程序
$(main): main.o make_log.o
	$(CC) $^ -o $@ $(LIBS)

#redis_test程序
$(redis_test): ./test/redis_test.o make_log.o redis_op.o
	$(CC) $^ -o $@ $(LIBS)

#程序
#$(login): login_cgi.o cJSON.o dao_mysql.o util_cgi.o make_log.o redis_op.o
#	$(CC) $^ -o $@ $(LIBS)

#test file info程序
#$(fdfs_file_info_test): test/test_fdfs_file_info.o cJSON.o dao_mysql.o util_cgi.o make_log.o redis_op.o
#	$(CC) $^ -o $@ $(LIBS)




#clean指令

clean:
	-rm -rf $(obj) $(target)

distclean:
	-rm -rf $(obj) $(target)

#将clean目标 改成一个虚拟符号
.PHONY: clean ALL distclean
