int my_atoi(const char * str){
	int res=0,begin=0,i;
	bool minus=false;
	while(*str!='/0'){
		if(begin==0&&(('0'<*str&&*str<'9')|| *str=='-') ) {
			begin=1;
			if(*str == '-'){
				minus=true;
				str++;
			}
		}
		else if(begin==1&&(*str<'0'||*str>'9') )           //遇到第一个非数字，退出
			break;
		if(begin==1)
			res=res*10+(*str-'0');                       //计算
		str++;
	}
	return minus? -res : res;
}