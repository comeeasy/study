#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define CREDIT 3
#define MAX_CLASS_CNT 60

int timetable[5][5];

typedef struct CLASS
{
	char name[20];
	char first_time[8];
	char second_time[8];
	int credit;	
} CLASS;

typedef struct CLASS_LIST
{
	CLASS _class[MAX_CLASS_CNT];
	int cnt;
} CLASS_LIST;

void set_class_list( CLASS_LIST* class_list )
{
	int n;
	
	FILE* fp = fopen("name.txt", "r");
	fscanf(fp,"%d", &n);
	class_list->cnt = n;
	
	for( int i=0; i<n; ++i )
	{
		fscanf(fp, "%s", class_list->_class[i].name);
	}	
	fclose(fp);
	
	fp = fopen("time.txt", "r");
	for( int i=0; i<n; ++i )
	{
		fscanf(fp,"%s", class_list->_class[i].first_time);
		fscanf(fp,"%s", class_list->_class[i].second_time);
	}
	fclose(fp);
	
}

void set_my_class( CLASS_LIST* my_class_list, CLASS _class )
{
	static int idx = 0;
	
	my_class_list->_class[idx++] = _class;
	my_class_list->cnt++;
}

char* get_time( int idx )
{
	FILE* fp = fopen("time.txt","r");
	char tmp[8];
	
	for( int i=0; i<idx; ++i )
		fscanf( fp, "%s", tmp );
	
	fclose( fp );
	return tmp;
}

//이 함수에서의 인덱스는 강의표에서의 인덱스 
int* get_timetable_idx( CLASS_LIST class_list, int idx )
{
	int _timetable[4];	
		
	char *Kor1, *Kor2;
	Kor1 = (char*)malloc(sizeof(char)*3);
	Kor2 = (char*)malloc(sizeof(char)*3);
	
	char Eng1[2], Eng2[2];
	char time1[8], time2[8];
	strcpy( time1, get_time( 2*idx-1 ) );
	strcpy( time2, get_time( 2*idx ) );
	
	//한글 시간과 영어 시간 분류 
	strcpy( Kor1, time1 );	
	Kor1[2] = '\0';
	strcpy( Eng1, time1+2 );

	strcpy( Kor2, time2 );
	Kor2[2] = '\0';
	strcpy( Eng2, time2+2 );

//first_time 의 요일	
	if( !strcmp( Kor1, "월" ) )
	{
		_timetable[0] = 0;				
	}
	else if( !strcmp( Kor1, "화" ) )
	{
		_timetable[0] = 1; 
	}
	else if( !strcmp( Kor1, "수" ) )
	{
		_timetable[0] = 2; 
	}
	else if( !strcmp( Kor1, "목" ) )
	{
		_timetable[0] = 3; 
	}
	else if( !strcmp( Kor1, "금" ) )
	{
		_timetable[0] = 4; 
	}
//second_time 의 요일	
	if( !strcmp( Kor2, "월" ) )
	{
		_timetable[2] = 0;				
	}
	else if( !strcmp( Kor2, "화" ) )
	{
		_timetable[2] = 1; 
	}
	else if( !strcmp( Kor2, "수" ) )
	{
		_timetable[2] = 2; 
	}
	else if( !strcmp( Kor2, "목" ) )
	{
		_timetable[2] = 3; 
	}
	else if( !strcmp( Kor2, "금" ) )
	{
		_timetable[2] = 4; 
	}
//first time 의 교시	
	if( !strcmp( Eng1, "A" ) )
	{
		_timetable[1] = 0;
	}
	else if( !strcmp( Eng1, "B" ) )
	{
		_timetable[1] = 1;
	}
	else if( !strcmp( Eng1, "C" ) )
	{
		_timetable[1] = 2;
	}
	else if( !strcmp( Eng1, "D" ) )
	{
		_timetable[1] = 3;
	}
	else if( !strcmp( Eng1, "E" ) )
	{
		_timetable[1] = 4;
	}
//second time 의 교시	
	if( !strcmp( Eng2, "A" ) )
	{
		_timetable[3] = 0;
	}
	else if( !strcmp( Eng2, "B" ) )
	{
		_timetable[3] = 1;
	}
	else if( !strcmp( Eng2, "C" ) )
	{
		_timetable[3] = 2;
	}
	else if( !strcmp( Eng2, "D" ) )
	{
		_timetable[3] = 3;
	}
	else if( !strcmp( Eng2, "E" ) )
	{
		_timetable[3] = 4;
	}
	
	free(Kor1);
	free(Kor2);
	
	return _timetable; 
}

void print_timetable()
{
	printf("================================시간출력====================================\n");
	printf("       월     화     수     목     금\n");
	for( int i=0; i<5; ++i )
	{
		printf("%c      ", 65+i);
		for( int j=0; j<5; ++j )
		{
			printf("%-7d", timetable[j][i]);
		}
		printf("\n");
	}
	printf("============================================================================\n");
}

void print_class_list( CLASS_LIST class_list )
{
	printf("============================================================================\n");
	printf("       %26s%10s%10s", "과목명", "1타임", "2타임\n");
	
	for( int i=0; i<class_list.cnt; ++i )
	{
		printf("%d.     %26s%10s%10s\n", i+1, class_list._class[i].name, class_list._class[i].first_time, class_list._class[i].second_time);
	}
	printf("============================================================================\n");
}

int check_timetable( CLASS_LIST class_list, int idx )
{
	int* index = get_timetable_idx( class_list, idx );
	int _index[4];
	_index[0] = *index;
	_index[1] = *(index+1);
	_index[2] = *(index+2);
	_index[3] = *(index+3);
		
	if(  timetable[ _index[0] ][ _index[1] ]  || timetable[ _index[2] ][ _index[3] ]   )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void set_timetable( CLASS_LIST* class_list, int idx )
{
	int* index = get_timetable_idx( *class_list, idx );
	
	timetable[ *index ][*(index+1)] = 1;
	timetable[ *(index + 2) ][ *(index+3) ] = 1;
}

void get_input_from_user( CLASS_LIST class_list )
{
	int idx;
	CLASS_LIST my_class_list;
	my_class_list.cnt = 0;
	
	for( int i=0; i<7; ++i )
	{
		printf("희망하는 과목을 입력하세요.(중단 : -1) :");
		scanf("%d", &idx);
		if( idx == -1 )
		{
			print_class_list( my_class_list );
			print_timetable();
			return; 
		}
		else if( idx >= 1 && idx <= class_list.cnt )
		{
			if( check_timetable( class_list, idx ) )
			{
				printf("선택한 과목 : \n");
				printf("%d.     %16s%10s%10s\n\n", i+1, class_list._class[idx-1].name, class_list._class[idx-1].first_time, class_list._class[idx-1].second_time);
				set_my_class( &my_class_list, class_list._class[idx-1] );
				set_timetable( &class_list, idx );
			}
			else
			{
				printf("시간표 중복입니다.\n\n");
				--i;
			}
		}
		else
		{
			printf("인덱스에서 벗어났습니다.\n");
			--i;
		}		
	}
	
	print_class_list( my_class_list );
	print_timetable();
	return; 
}

int main()
{
	CLASS_LIST class_list;
	
	set_class_list( &class_list );
	//set timetable 0
	for( int i=0; i<5; ++i )
		for( int j=0; j<5; ++j )
			timetable[i][j] = 0;
	
	print_class_list( class_list );
	
	get_input_from_user( class_list );
	return 0;
}