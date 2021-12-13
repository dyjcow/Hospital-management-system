typedef struct patient//医生和用户登录数据共用的结构体 
	{
	    char user[30];
	    char name[30];
	    char password[30];
	    char office[30];
	    struct patient *next;
	}Patient;
		
typedef struct list//对结构体设置头尾指针 
	{
	    Patient *head;
	    Patient *tail;
	}List;
	
typedef struct formp// 医生和用户的出诊及预约数据共用结构体 
	{
        char user[30];
	    char name[30];
	    int timeYear;
        int timeMon;
        int timeDay;
	    char office[30];
	    char doctor[30];
        int number;
	    struct formp *next;
	}Formp;
		
typedef struct formlistp//对结构体设置头尾指针
	{
	    Formp *head;
	    Formp *tail;
	}Formlistp;
	

struct tm //对time.h里结构体tm的再次声明，工程文件中无法自主读取 
{
   int tm_sec;         /* 秒，范围从 0 到 59        */
   int tm_min;         /* 分，范围从 0 到 59        */
   int tm_hour;        /* 小时，范围从 0 到 23        */
   int tm_mday;        /* 一月中的第几天，范围从 1 到 31    */
   int tm_mon;         /* 月，范围从 0 到 11        */
   int tm_year;        /* 自 1900 年起的年数        */
   int tm_wday;        /* 一周中的第几天，范围从 0 到 6    */
   int tm_yday;        /* 一年中的第几天，范围从 0 到 365    */
   int tm_isdst;       /* 夏令时                */
};


int n = 0;//记录用户数量的全局变量 
int m = 0;//记录医生数量的全局变量
int inputp = 0;//记录预约数量的全局变量
int inputd = 0;//记录出诊数量的全局变量
