#include <Python.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* PyObject : object  structure to define object types for Python */
static PyObject *levenshtein(PyObject *self, PyObject *args){
	
	char *string1, *string2 = NULL;


	/* Parse arguments */
	if(!PyArg_ParseTuple(args,"ss",&string1,&string2)){
		/*args are type of PyObject, ss is format specifier 

		&str and &filename are pointers to local variables */
		return NULL;
	}

	int length_1 = strlen(string1);
    int length_2 = strlen(string2);

    int tab[length_1+1][length_2+1];

    for(int i = 0 ; i<length_2+1; i++){
        tab[0][i] = i;
    }

    for(int i = 0; i<length_1+1; i++){
        tab[i][0] = i;
    }

    for(int i=1; i<length_1+1; i++) {
          for(int j=1;j<length_2+1;j++) {
            tab[i][j]=0;
           
          }
       
    }

    int cost;

    for(int i=1; i<length_1+1; i++) {
        for(int j=1;j<length_2+1;j++) {

            if(string1[i-1] == string2[j-1]){
                cost = 0 ;
            }else{
                cost = 1 ;
            }

            if((tab[i-1][j]+1 <= tab[i][j-1]+1) && (tab[i-1][j]+1 <= tab[i-1][j-1]+cost)) tab[i][j] = tab[i-1][j]+1;
            if((tab[i][j-1]+1 <= tab[i-1][j]+1) && (tab[i][j-1]+1 <= tab[i-1][j-1]+cost)) tab[i][j] = tab[i][j-1]+1;
            if((tab[i-1][j-1]+cost <= tab[i][j-1]+1) && (tab[i-1][j-1]+cost <= tab[i-1][j]+1)) tab[i][j] = tab[i-1][j-1]+cost;
            
        }
          
    }

	


	/* return PyLongObject which is an integer in Python*/
	return PyLong_FromLong(tab[length_1][length_2]);
}


static PyMethodDef LevenshteinMethods[] = {
	/*tell python module about the method (def)

	fputs: name the user need to write to call

	method_fputs: name of the C function to invoke

	METH_VARARGS: flag that tell the interpreter that the 
	function accept two arguments of type PyObject
	
	final string is a docstring

	*/
	{"levenshtein",levenshtein,METH_VARARGS,"Python interface for levenshtein distance"},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef levenshteinmodule = {
	/* Information about the module */
	PyModuleDef_HEAD_INIT,
	"levenshtein",// name of the module
	"Python interface for levenshtein distance", //description
	-1, // memory requirements
	LevenshteinMethods // ref to methode definition

};

PyMODINIT_FUNC PyInit_levenshtein(void) {
    return PyModule_Create(&levenshteinmodule);
    //when importing for first time create module
}
