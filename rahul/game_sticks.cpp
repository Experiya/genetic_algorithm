#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
char ch;
struct node{
    int data;
    int label;
    int winner;
    struct node *left,*mid,*right;
};
int select(struct node *);
int drive(int n,int turn,int type){
    int k;
    if(type==0){
	 	if(turn==0){
	        struct node *temp=new struct node();
	        temp->data=n;
	        temp->label=0;
	        temp->winner=0;
	        temp->left=temp->mid=temp->right=NULL;
	        k=select(temp);
	        if(n==1){
	        	cout<<"***Winner : YOU***\n";
			}
			else{
	        cout<<"\n\t\t\t\t\t\t\t\t\t<--P2  "<<k<<"\n";
	        	if(turn==1){
	            turn=0;
	        	}
				else{
	            turn=1;
				}
	        drive(n-k,turn,type);
			}
	    }
		else{
	    	cout<<"\t\t\t\t There is ["<<n<<"] no of sticks remaining\n";
	    	if(n==1){
	    		cout<<"***Winner : COMPUTER***\n";
			}
			else{
		    	l:
		        cout<<"\t\t\tP1-->";
		        cin>>k;
		        if(k>=0&&k<=3){
		        	if(n-k==0){
					cout<<"***Winner : COMPUTER***\n";
					system("cls");
					}
					else{
			        	if(turn==1){
			            turn=0;
						}
						else{
			            turn=1;
			        	}
			        	drive(n-k,turn,type);
			    	}	
				}
				else{
					cout<<"\t\t\twrong input\n";
					goto l;
				}
			}
	    }
	}
	else if(type==1){
		if(turn==0){
			struct node *temp=new struct node();
	        temp->data=n;
	        temp->label=0;
	        temp->winner=0;
	        temp->left=temp->mid=temp->right=NULL;
	        k=select(temp);
	        if(n==1){
	        	cout<<"\t\t\t\t There is ["<<n<<"] no of sticks remaining\n";
	        	cout<<"***Winner : P2***\n";
			}
			else{
	        cout<<"\t\t\tP1-->"<<k<<"\n";
	        	if(turn==1){
	            	turn=0;
				}
				else{
	            turn=1;
	        	}
	        drive(n-k,turn,type);
			}
			}
			else{
				struct node *temp=new struct node();
		        temp->data=n;
		        temp->label=0;
		        temp->winner=0;
		       	temp->left=temp->mid=temp->right=NULL;
		        k=select(temp);
		        if(n==1){
		        	cout<<"\t\t\t\t There is ["<<n<<"] no of sticks remaining\n";
		        	cout<<"***Winner : P1***\n";
				}
				else{
		        	cout<<"\n\t\t\t\t\t\t\t\t\t<--P2  "<<k<<"\n";
		        	if(turn==1){
		            	turn=0;
					}
		        	else{
		            turn=1;
		    	}
		        drive(n-k,turn,type);
			}
		}
	}
}
int main(){
	srand(time(NULL));
    int t,k,m,n,turn;
    cout<<"Test case's : ";
    cin>>t;
    cout<<"**************************************************\n\n\n\n";
	cout<<"\t    Wellcome to sticks game\n\n";
	cout<<"******************  MENU  ************************\n\n";
    while(t--){	
    	o:
		cout<<"\n1.Human v/s AI\t\t2.AI v/s AI\n\n$";
    	cin>>m;
		if(m>=1&&m<=2)
		{
	    	switch(m){
	    		case 1:{
	    			p:
			    	cout<<"\n1. 14\t\t2. 21\t\t3. 53\t\t4.cumtome\n\n";
			    	cout<<"$";
			    	cin>>k;
			        if(k==1){
			        	n=14;
					}
					else if(k==2){
						n=21;
					}
					else if(k==3){
						n=52;
					}
					else if(k==4){
						cout<<"No. of Sticks : ";
						cin>>n;
						system("cls");
					}
					else{
						cout<<"Wrong input\n";
						goto p;
					}
					system("cls");
			        turn=rand()%2;
			        if(turn==0){
			        	cout<<"\n[Computer's turn]\n\n";
					}else{
						cout<<"\n[Your's turn]\n\n";
					}
			        drive(n,turn,0);
					break;
				}
				case 2:{
					q:
			    	cout<<"\n1. 14\t\t2. 21\t\t3. 53\t\t4.cumtome\n\n";
			    	cout<<"$";
			    	cin>>k;
			        if(k==1){
			        	n=14;
					}
					else if(k==2){
						n=21;
					}
					else if(k==3){
						n=52;
					}
					else if(k==4){
						cout<<"No. of Sticks : ";
						cin>>n;
						system("cls");
					}
					else{
						cout<<"Wrong input\n";
						goto q;
					}
					system("cls");
					turn=rand()%2;
			        if(turn==0){
			        	cout<<"\n[AI 1's(p1) turn]\n\n";
					}else{
						cout<<"\n[AI 2's(p2) turn]\n\n";
					}
			        drive(n,turn,1);
					break;
				}
	    	}
		}
		else{
			cout<<"Wrong input\n";
			goto o;
		}
    }
}
int select(struct node *temp){
    int best=1;
    if(temp->data==0){
        if(temp->label%2==0)
            return 1;
        else
            return 0;
    }else{
        struct node *left=new struct node();
        struct node *mid=new struct node();
        struct node *right=new struct node();
        
        left->data=temp->data-1;
        left->label=temp->label+1;
        left->left=left->mid=left->right=NULL;
        temp->left=left;

        mid->data=temp->data-2;
        mid->label=temp->label+1;
        mid->left=mid->mid=mid->right=NULL;
        temp->mid=mid;

        right->data=temp->data-3;
        right->label=temp->label+1;
        right->left=right->mid=right->right=NULL;
        temp->right=right;

        if(temp->label%2==0){
            left->winner=0;
            mid->winner=0;
            right->winner=0;
        }
		else{
            left->winner=1;
            mid->winner=1;
            right->winner=1;
        }
		//................................1
        if(temp->data-1>=0){
            left->winner=select(left);
        }
        if(temp->data-2>=0){
            if(temp->label%2==0){
                if(left->winner!=1){
                    mid->winner=select(mid);
                }
            }
			else{
                if(left->winner!=0){
                    mid->winner=select(mid);
				}
            }
        }
        //......................................2
        if(temp->data-3>=0){
            if(temp->label%2==0){
                if(left->winner!=1&&mid->winner!=1){
                    right->winner=select(right);
                }
            }
			else{
                if(left->winner!=0&&mid->winner!=0){
                    right->winner=select(right);
                }
            }
        }
        //.........................................3
        if(temp->label%2==0){
            if(left->winner==1||mid->winner==1||right->winner==1){
                temp->winner=1;
			}
            else{
                temp->winner=0;
			}
        }
		else{
            if(left->winner==1&&mid->winner==1&&right->winner==1&&temp->label!=0){
                temp->winner=1;
            }
            else{
                temp->winner=0;
			}
        }
        //..............................................4
        if(temp->label==0){
            if(temp->winner==1){
                if(left->winner==1){
                    return 1;
                }
                else if(mid->winner==1){
                    return 2;
				}
                else{
                    return 3;
				}
            }
			else{
                return 1;
            }
        }
		else{
            if(temp->winner==1){
                return 1;
			}
            else{
                return 0;
			}
        }
    }
    return 0;
} 
