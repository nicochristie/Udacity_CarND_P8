#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */

  // Update (D)ifferential term first
  d_error = cte - p_error;  // Current-Last measure
  i_error += cte;           // Add current measure
  p_error = cte;            // Assign current measure
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  
  return -Kp * p_error - Kd * d_error - Ki * i_error;  // TODO: Add your total error calc here!
}

double PID::Abs(double value) {
  if (value < 0) return -value;
  return value;
}
