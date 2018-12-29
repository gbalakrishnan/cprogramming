#ifndef _TJSIM_H_
#define _TJSIM_H_

enum traffic_light{OFF, ON};


// intial values for the simulation to start
void init_tjsim(const int maxiter,
                const int iwenv, const int isnnv,
                const int iwewt, const int isnwt,
                enum traffic_light isnlight,
                const int mnwv,
                const int mwt);

// run the simulation
void simulate(void);
#endif
