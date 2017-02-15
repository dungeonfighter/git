1:亂數問題 ，一開始能產生亂數，但要重開程式才能有新亂數，導入time.h以及srand(time(NULL))依時間產生亂數
  後功能才正式完成

2:const int不能對應int，指標也是，const要對const

3:指標存取普通變數要&，指標要存取指標的內容(非指標本身地址)不用&，直接等於就好
  eg: int* p ;
  	  int* b;
  	  int a ;
  	  b=&a;
  	  p=b;