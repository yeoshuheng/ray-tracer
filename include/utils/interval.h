#ifndef RAY_INTERVAL_H
#define RAY_INTERVAL_H

#define INF std::numeric_limits<double>::infinity()

class interval {
    public:

        double min, max;

        interval() { min = -INF; max = INF; };
        
        interval(double _min, double _max) { min = _min; max = _max; }

        double size() const { return max - min; }

        bool contains(double x) const { return min <= x && x <= max; }

        bool surrounds(double x) const { return min < x && x < max; } 

        // static classes to represent a empty world and the full world.
        static const interval empty;
        static const interval universe;

};

#endif