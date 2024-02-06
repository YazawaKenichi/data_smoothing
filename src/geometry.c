#include "math.h"
#include "geometry.h"

Pose f(Pose P_t_1, Unit u_t, float dt)
{
    float _x, _y, _t;
    float v, w;
    _x = P_t_1.x;
    _y = P_t_1.y;
    _t = P_t_1.t;
    v = u_t.v;
    w = u_t.w;
    if(abs(w) < 0.0000000001f)
    {
        Pr.x = _x + v * cos(_t) * dt;
        Pr.y = _y + v * sin(_t) * dt;
        Pr.t = _t + w * dt;
    }
    else
    {
        Pr.x = _x + v * powwer(w, -1) * ( sin(_t + w * dt) - sin(_t));
        Pr.y = _y + v * powwer(w, -1) * (-cos(_t + w * dt) + cos(_t));
        Pr.t = _t + w * dt;
    }
    return Pr;
}

