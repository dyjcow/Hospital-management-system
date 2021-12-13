int timeJudge(int year, int month, int day)//时间判断函数，计算与现在的时间差
{
	time_t now_time = 0, set_time = 0;
	struct tm q;
	q.tm_year = year-1900;
	q.tm_mon = month-1;
	q.tm_mday = day;
	q.tm_hour = 0;
	q.tm_min = 0;
	q.tm_sec = 0;
	q.tm_isdst = 0;
	set_time = mktime(&q);
	time(&now_time);
	return now_time - set_time;
}
