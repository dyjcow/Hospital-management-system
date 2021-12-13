int timecpy(int year, int month, int day,int year1, int month1, int day1)//两时间差的计算 
{
	time_t set1_time = 0, set_time = 0;
	struct tm p;
	p.tm_year = year-1900;
	p.tm_mon = month-1;
	p.tm_mday = day;
	p.tm_hour = 0;
	p.tm_min = 0;
	p.tm_sec = 0;
	p.tm_isdst = 0;
	set_time = mktime(&p);
	struct tm q;
	q.tm_year = year1-1900;
	q.tm_mon = month1-1;
	q.tm_mday = day1;
	q.tm_hour = 0;
	q.tm_min = 0;
	q.tm_sec = 0;
	q.tm_isdst = 0;
	set1_time = mktime(&q);
	return set1_time - set_time;
}
