#include <stdio.h>
#include <stdlib.h>

struct PageTable{
	int R;
	int frame;
};

struct FrameTable{
	int age;
	int page;//хех
};

int main(void){	

	struct PageTable *PageTable;
	struct FrameTable *FrameTable;
	
	int numb_frames;
	printf("Input the number of frames, please: ");
	scanf("%d", &numb_frames);
	
	PageTable = malloc(sizeof(PageTable));
	FrameTable = malloc(sizeof(FrameTable) * numb_frames);
	
	int i = 0;
	for (i = 0; i < numb_frames; i++){
	FrameTable[i].age = 0;
	}
	
	int req_page, count = 0, frame_table_count = 0, miss_count = 0, hit_count = 0;

	FILE *input = fopen("input.txt", "r"); 
	while(!feof(input)){
		// break if the frame_table contains all the frames
		if(frame_table_count == numb_frames){
			break;
		}
		//read the page 
		fscanf(input,"%d", &req_page);
		count++;
		
		//if the page is present -> hit
		if(PageTable[req_page].R == 1){
			hit_count++;
		}
		//else it's missed->
		// miss -> put the page into page_table, make R 1(referenced), increase the number of frames
		else{
			miss_count++;
			FrameTable[frame_table_count].page = req_page;
			PageTable[req_page].frame = frame_table_count;
			frame_table_count++;	
			PageTable[req_page].R = 1;			
		}
	}
	//continue reading
	while(!feof(input)){
		fscanf(input,"%d", &req_page);
		count++;
		//increasing age with shifting(recently referenced have higher priority)
		int i = 0;
		for ( i = 0; i < numb_frames; i++){
		FrameTable[i].age = (FrameTable[i].age/2)+1;
	}
		// if required page is in the frame_table -> hit
		if (PageTable[req_page].R == 1){
			hit_count++;
		}
		else{
			miss_count++;
			// else find the oldest referenced page, and replace it
			int old_page, i = 0, oldest = -1;
	            for (i = 0; i < numb_frames; i++){
		            if(oldest  < FrameTable[i].age){
			            oldest = FrameTable[i].age;
    			        old_page = i;
		            }           
            	}
			PageTable[FrameTable[old_page].page].R = 0;
			FrameTable[old_page].age = 0;
			FrameTable[old_page].page = req_page;
			PageTable[req_page].frame = old_page;
			//mark the inserted page as references
			PageTable[req_page].R = 1;
		}
		
	}
	fclose(input);
	free(FrameTable);
	free(PageTable);
	
	float r = (float)hit_count/(float)miss_count;
	printf("The hit/miss ratio = %f\n",r);

	return 0;
}

