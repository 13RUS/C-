//
// Created by Aleksey Leshchankin on 14.02.2023.
//

#include <Eigen/Dense>
#pragma once

class KalmanFilter {
public:

    // -- Create a Kalman filter with the specified matrices --
    /*
     A - System dynamics matrix
     C - Output matrix
     Q - Process noise covariance
     R - Measurement noise covariance
     P - Estimate error covariance
    */

    KalmanFilter (
            double dt,
            const Eigen::MatrixXd& A,
            const Eigen::MatrixXd& C,
            const Eigen::MatrixXd& Q,
            const Eigen::MatrixXd& R,
            const Eigen::MatrixXd& P
            );

    //-- Create a blank estimator --
    KalmanFilter();

    //-- Initialize filter with inintial states at zero --
    void init ();

    //-- Initialize filter with a guess for initial states --
    void init (double t0, const Eigen::VectorXd& x0);

    //-- Update the estimated state based on measured values. The time step is const --
    void update (const Eigen::VectorXd& y);

    //-- Update the estimated state based on measured values, using time step and dynamics matrix--
    void update (const Eigen::VectorXd& y, double dt, const Eigen::MatrixXd A);

    //-- Return the current state and time --
    Eigen::VectorXd state () { return x_hat; }
    double time () { return t; }

private:
    Eigen::MatrixXd A, C, Q, R, P, K, P0;

    //-- System dimensions --
    int m, n;

    //-- Initial and current time --
    double t0, t;

    //-- Discrete time step --
    double dt;

    //-- Is filter initialized --
    bool is_initialized;

    //-- n-size identity --
    Eigen::MatrixXd I;

    //-- Estimated states --
    Eigen::VectorXd x_hat, x_hat_new;
};