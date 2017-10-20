/*************************************************************************
* Timers.h - Instrumentation Macros Module  - Student file
*
* The timing instrumentation macros can be globally enabled by setting 
* the variable EN_TIME (ENable TIMErs) in the compiler command line, e.g., 
* use "gcc -DEN_TIME...." to enable the timers when needed.
* A compiler warning will be issued when the timers are enabled.  
* Note: All timing output should be directed to stderr.
*
*  10/08/2016   R. Repka    Fixed C++ struct warnings 
*  12/03/2016   R. Repka    Added semicolon to DECLARE_TIMER
**************************************************************************/
#ifndef _TIMERS_H_
#define _TIMERS_H_

/*************************************************************************
 * It is important that the user know that the timers are enabled when the
 * code is compiled. The following pre-processor code issues a warning and
 * includes the necessary system header files when the timers are enabled.
*************************************************************************/
#if defined(EN_TIME)
	#include<stdio.h>
	#include<time.h>
	#if defined(WARNING_MSG)
	#warning Timers enabled! Execution could be adversly effected.
	#endif
#endif


#if defined(EN_TIME)							

  #define DECLARE_TIMER(A)						\
    struct timmerDetails {              				\
      clock_t Start;    /* Start Time   - set when the timer is started */	\
      clock_t Stop;     /* Stop Time    - set when the timer is stopped */	\
      clock_t Elapsed;  /* Elapsed Time - Accumulated when the timer is stopped */\
      int State;        /* Timer State  - 0=stopped / 1=running */	\
      }									\
     A = /* Elapsed Time and State must be initialized to zero */       \
      {                                                                 \
      /* Start   = */ 0,                                                \
      /* Stop    = */ 0,                                                \
      /* Elapsed = */ 0,                                                \
      /* State   = */ 0,                                                \
      } /* Timer has been declared and defined,   ;  IS required */	

/* Write the timing macros here */					

  #define START_TIMER(A)						\
  {									\
    if (1 == A.State){							\
      fprintf(stderr, "Error, running timer "#A" started. \n");		\
    }									\
    A.State = 1;							\
    A.Start = clock();							\
  }									

  #define RESET_TIMER(A)						\
  {									\
    A.Elapsed = 0;							\
  }									

  #define STOP_TIMER(A)							\
  {									\
    A.Stop = clock();							\
    if (0 == A.State){							\
      fprintf(stderr, "Error, stopped timer "#A" stopped again. \n");	\
    }									\
    else{								\
      A.Elapsed += A.Stop - A.Start;					\
    }									\
    A.State = 0;							\
  }									

  #define PRINT_TIMER(A)						\
  {									\
    if (1 == A.State){							\
      STOP_TIMER(A);							\
    }									\
    fprintf(stderr, "Elapsed CPU time ("#A") = %g sec. \n",		\
			(double)A.Elapsed/(double)CLOCKS_PER_SEC);	\
  }								





  #define PRINT_RTIMER(A,R)						\
  {									\
    if (1 == A.State){							\
      STOP_TIMER(A);							\
    }									\
    fprintf(stderr, "Elapsed CPU time per Iteration("#A", %d) = %.2e sec. \n",	\
		R, ((double)A.Elapsed/(double)CLOCKS_PER_SEC)/(double)R);	\
  }										

  #define DECLARE_REPEAT_VAR(V)						\
      int V;								

  #define BEGIN_REPEAT_TIMING(R,V)					\
  {									\
    for(V = 0; V < (R); V++){				

#define END_REPEAT_TIMING						\
     }									\
  }									

#else /* not defined(EN_TIME) */					
 /* Declare null macros for error-free compilation*/			
 #define DECLARE_TIMER(A)
 #define START_TIMER(A)
 #define RESET_TIMER(A)
 #define STOP_TIMER(A)
 #define PRINT_TIMER(A)
 #define PRINT_RTIMER(A,R)
 #define DECLARE_REPEAT_VAR(V)
 #define BEGIN_REPEAT_TIMING(R,V)
 #define END_REPEAT_TIMING

#endif /* defined(EN_TIME) */
#endif /* _TIMERS_H_ */
