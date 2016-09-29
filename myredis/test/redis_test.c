#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hiredis.h"
#include "redis_op.h"


int main(void)
{
	int   retn = 0; 
	int   reply = 0;
	char* value = NULL;
	redisContext* redis_c = NULL;
	redis_c = rop_connectdb_nopwd("127.0.0.1", "6379");
	value = (char*)malloc(1024);
	memset(value, 0, 1024);
	if(NULL == value)
	{
		printf("value malloc err\n");
		return retn;
	}
	if(NULL == redis_c)
	{
		printf("rop_connectdb_nopwd err\n");
		return 1;	
	}
	
	//测试取数据
	reply = rop_get_string(redis_c, "test11", value);
	if(-1 == reply)
	{
		retn = -1;
		goto END;
	}
	if(NULL == value)
	{
		printf("key没有对应的值\n");
		goto END;
	}
	printf("%s\n", value);


	//测试获取指定hash表中的值
	memset(value, 0, 1024);
	reply = rop_get_one_hash_table(redis_c, "test_hast", "name", value);
	if(-1 == reply)
	{
		retn = -1;
		goto END;
	}
	
	if(NULL == value)
	{
		printf("hash表中field没有对应的值\n");
		goto END;
	}
	printf("%s\n", value);
END:
	free(value);
	return retn;
}
