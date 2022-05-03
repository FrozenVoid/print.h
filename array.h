#pragma once
#include <stdint.h>
#include <stddef.h>
/*array.h array macros
https://github.com/FrozenVoid/array.h
arrmax(arr,elems) find maximum
arrmin(arr,elems) find minimum
arrfavg(arr,elems) array average(long double)
arriavg(arr,elems) array average(int64_t)
arrimap(arr,elems,func) each element is transformed by func
arrcmap(arr,elems,func) call func(x) with each element
arrfold(arr,elems,func) apply func to accumulator and each element
arrall(arr,elems,func) true if applying func
 on each element returns true
arrany(arr,elems,func) true of applying func
 on any element returns true

//fill array with val
#define arrfill(arr,elems,val)
//fill array with func(index)
#define arrfilli(arr,elems,func)


//copy [a]->[b]
#define arrcopy(dest,src,len)
//copy to [*ptr+i]
#define arrsetlocs(dest,locs,src,len)
//copy from [*ptr+i]
#define arrcopylocs(dest,src,locs,len)



*/

#define arrfold(arr,elems,func) ({;\
typeof(arr[0]) foldacc=arr[0];\
for(size_t i=1;i<elems;i++){\
foldacc=func(foldacc,arr[i]);};foldacc;})

#define maxelem(a,b) ((b)<(a)?(a):(b))
#define minelem(a,b) ((b)>(a)?(a):(b))
#define arrmax(arr,elems) arrfold(arr,elems,maxelem)
#define arrmin(arr,elems) arrfold(arr,elems,minelem)
#define arrimap(arr,elems,func) ({\
for(size_t i=0;i<elems;i++){arr[i]=func(arr[i]);};arr;})
#define arrcmap(arr,elems,func) ({\
for(size_t i=0;i<elems;i++){func(arr[i]);};arr;})


#define arrfavg(arr,elems) ({long double  arrq=arr[0];\
for(size_t i=1;i<elems;i++)arrq+=arr[i];arrq/elems;})
#define arriavg(arr,elems) ({int64_t   arrq=arr[0];\
for(size_t i=1;i<elems;i++)arrq+=arr[i];arrq/elems;})


#define arrall(arr,elems,func) ({;\
size_t i=0;for(;i<elems &&(func(arr[i]));i++);;i==elems;})

#define arrany(arr,elems,func) ({;\
int arrhas=0;for(size_t i=0;i<elems;i++){\
if(func(arr[i])){arrhas=1;break;}};;arrhas;})

#define arrfill(arr,elems,val) ({;for(size_t i=0;i<elems;i++){arr[i]=val;};arr;})
#define arrfilli(arr,elems,func) ({;for(size_t i=0;i<elems;i++){arr[i]=func(i);};arr;})


//copy [a]->[b]
#define arrcopy(dest,src,len) ({for(size_t i=0;i<len;i++)dest[i]=src[i];dest;})
//copy to [*ptr+i]
#define arrsetlocs(dest,locs,src,len) ({for(size_t i=0;i<len;i++)dest[locs[i]]=src[i];dest;})
//copy from [*ptr+i]
#define arrcopylocs(dest,src,locs,len) ({for(size_t i=0;i<len;i++)dest[i]=src[locs[i]];dest;})
