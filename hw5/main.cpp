#include <iostream>
#include <conio.h>
#include <time.h>
 using namespace std;
 struct  file_system{            
     char file_name [10]; 
	 int file_cr [3]; 
	 int file_response;};

   struct NODE {
	 file_system file; 
	 NODE *next; 
	 NODE *prev; 

 };

   NODE *first(file_system file);
   NODE *find(NODE *const pbeg , int i);
   bool remove(NODE**pbeg , NODE **pend, int key);

   void get_info (file_system file , NODE *pb){
	   

	   cout<<"File name:"<< pb->file.file_name<<"\n";
	   cout<<"File creation date:";
	   for(int i=0;i<3;i++){
		cout<<pb->file.file_cr[i]<<".";}
	   cout<<"\n";
	   cout<<"File responses:"<<pb->file.file_response<<endl;
	   
	    
   }

 file_system **fill (file_system *file){
 srand(time(NULL));
 int first_value = 1990;

cout<<"Enter file name:";
cin>>file->file_name;
file->file_cr[0]=1+rand()%29;
file->file_cr[1]=1+rand()%11;
file->file_cr[2]=first_value+rand()%15;
cout<<"File data creation is :"<<file->file_cr[0]<<"."<<file->file_cr[1]<<"."<<file->file_cr[2]<<"\n";
file->file_response=rand()%10; 
cout<<"number of cals is seted up:"<<file->file_response<<endl;
return &file;
 }

 NODE * add_first (file_system file){

	 NODE *pv =  new NODE;
	 pv->file=file;
	 pv->next=0;
	 pv->prev=0;
	 return pv;
 }


 NODE *find (NODE * const pbeg , int key[]) { // return data
	NODE *pv = pbeg;
	bool flag = false;
	while(pv){ 

		for(int i=2;i>=0;i--){
		if(pv->file.file_cr[i]<key[i]){
			flag=true;
			break; }
		}

		if(flag==true) break;
		else pv = pv->next;

	}
	return pv	;
 }




 int find_fewer(NODE *const pbeg,int key[]){
	 int counter=0;
	 	NODE *pv = pbeg;
	 
	while(pv){ 

		for(int i=2;i>=0;i--){
		if(pv->file.file_cr[i]<key[i]){
			counter++;
			break; }
		}
		pv = pv->next;

	}
	return counter	;


 }


NODE *find_respon (NODE *  pbeg  ) { // return data
	NODE *pv = pbeg;
	bool flag = false;
	NODE *resp = pbeg;
	
	while(pv){ 
        if(pbeg->file.file_response < pv->file.file_response){
		  
			pbeg=pv;
		}
      pv = pv->next;
	}
	return pbeg	;
 }




void add_sort (NODE **pbeg , NODE **pend , file_system file){
	bool checker=false;
	NODE *pv = new NODE;
	pv->file=file;
	NODE *pt = *pbeg;
	while(pt){
	  
		for(int i=2;i>=0;i--){
			if(file.file_cr[i] < pt->file.file_cr[i]){
			 checker=true;
			 pv->next = pt;
			 if(pt==*pbeg){
				 pv->prev=0;
				 *pbeg=pv;}
			 }

			else
			{
				(pt->prev)->next=pv;
				pv->prev=pt->prev;
			}
			pt->prev=pv;
			return;
			
			}
		pt=pt->next;
		}
	pv->next=0;
	pv->prev=*pend;
	(*pend)->next=pv;
	*pend=pv;
	}





bool remove (NODE ** pbeg, NODE **pend , int key [3]){
if(NODE *pkey = find(*pbeg, key)){
	if(pkey==*pbeg) {
		*pbeg=(*pbeg)->next;
		(*pbeg)->prev= 0;}
	else if(pkey==*pend){
		*pend = (*pend)->prev;
		(*pend)->next=0;}
	else {
		(pkey->prev)->next= pkey->next;
		(pkey->next)->prev = pkey->prev;}
	delete pkey;
	return true;
	}
return false;
}


 void add(NODE **pend , file_system file){
 fill(&file);

	NODE *pv = new NODE;
	pv->file = file;
	pv->next=0; 
	pv->prev=*pend;
	(*pend)->next=pv;
	*pend=pv;
 }


 int main(){

int n ;
cout<<"How much files you want to place in?:";
cin>>n;

file_system file;
 fill(&file);

NODE *pbeg = add_first(file);
NODE *pend = pbeg;


 for( int i=0;i<n-1;i++){
	add(&pend ,file);
	cout<<endl;}

NODE *pb = pbeg;

  system("cls");
 int l=1;
 
 while(pb){
	cout<<l<<")";
l++;
	get_info(file , pb);
	cout<<endl;
pb=pb->next;

  }




  cout<<"enter date. All the files which were creater earlier will be deleted.";
	int date [3];
	 cin>>date[0]>>date[1]>>date[2];
	 int node_del = find_fewer(pbeg,date);

	 cout<<"nodes which should be deleted:"<<node_del<<endl;
	 if(node_del==n){
		 cout<<"Empty list"<<endl;
		 exit(1);
	 }

	

	 for(int i=0;i<node_del;i++){
if(!remove(&pbeg, &pend , date)) cout<<"Not found";
	 }
	 system("cls");
NODE *kit = pbeg;
while(kit){

	get_info(file,kit);
	kit=kit->next;
}


  // Shows thw file which has more resp
cout<<"------------------------------------ \n";
cout<<"Find more responses after deleting file"<<endl;
NODE *p_b = pbeg;
get_info(file ,find_respon(pbeg));
cout<<"------------------------------------ \n";



 return 0;}