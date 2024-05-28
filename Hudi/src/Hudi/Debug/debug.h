#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <numeric>
#include <typeinfo>
#include <sstream>
#include <iomanip>
#include <time.h>

using namespace std;

// ----------------------------------------------------------------------------------------- //

#define _B   1LL
#define _KB  1'000LL
#define _MB  1'000'000LL
#define _GB  1'000'000'000LL

// ----------------------------------------------------------------------------------------- //

#define __MAX_OUTPUT_SIZE (500 * _KB)

// ----------------------------------------------------------------------------------------- //

class __Printer {
public:
    template <typename T>
    __Printer& operator<< (const T& __data) {
        auto& __ostream_target = *_ostream_target;

        if (!_output_unlimited && _output_size_counter > _CAPACITY) 
            return *this;
        clock_t start = clock();

        stringstream buffer;
        this->__print(buffer, __data);
        if (buffer.str().back() != '\n' && _space != -1)
            buffer << _space;
        uint64_t buffer_size = buffer.str().size() * sizeof(char);
        
        if (_output_unlimited || _output_size_counter + buffer_size <= _CAPACITY) {
            __ostream_target << buffer.str();
            _output_size_counter += buffer_size;
        }
        else {
            __ostream_target << "...\n";
            __ostream_target.flush();
            _output_size_counter = _CAPACITY + 1;
        }

        clock_t end = clock();
        _debug_time += end - start;
        return *this;
    }

    void _set_ostream_target(const std::string& file = "") {
        if (file.empty()) {
            _ostream_target = &std::cout;
            return;
        }

        _ostream_target = new std::ofstream(file);
    }

    void _set_output_unlimited(bool output_unlimited = true) { this->_output_unlimited = output_unlimited; }

    void _set_space(char space = ' ') { this->_space = space; }

    __Printer() {
        _start = clock();
    }

    ~__Printer() {
        clock_t end = clock();
        auto& __ostream_target = *_ostream_target;
        __ostream_target << "\n----------------------------------------------\n";
        __ostream_target << "[Time taken]: " << (end - _start) << " ms\n";
        __ostream_target << "[Time taken without debugging]: " << (end - _start - _debug_time) << " ms\n";
        __ostream_target.flush();

        if (_ostream_target != &std::cout)
			delete _ostream_target;
    }

private:
    template <typename T>
    void __print(ostream& out, const T& __data) {
        out << __data;
    }
    template <typename T, typename V>
    void __print(ostream& out, const pair<T, V>& p) {
        out << "[";
        this->__print(out, p.first);
        out << ", ";
        this->__print(out, p.second);
        out << "]"; 
    }
    template <typename T>
    void __print(ostream& out, const vector<T>& v) {
        out << "{ ";
        for(int i=0; i<v.size(); i++) {
            if (i != 0)
                out << ", ";
            out << "(" << i << ": ";
            this->__print(out, v[i]);
            out << ")";
        }
        out << " }";
    }
    template <typename T>
    void __print(ostream& out, const set<T>& s) {
        out << "{ ";
        for(auto it = s.cbegin(); it != s.cend(); it++) {
            if (it != s.cbegin())
                out << ", ";
            this->__print(out, *it);
        } 
        out << " }";
    }
    template <typename T>
    void __print(ostream& out, const unordered_set<T>& s) {
        out << "{ ";
        for(auto it = s.cbegin(); it != s.cend(); it++) {
            if (it != s.cbegin())
                out << ", ";
            this->__print(out, *it);
        } 
        out << " }";
    }
    template <typename T>
    void __print(ostream& out, const multiset<T>& s) {
        out << "{ ";
        for(auto it = s.cbegin(); it != s.cend(); it++) {
            if (it != s.cbegin())
                out << ", ";
            this->__print(out, *it);
        } 
        out << " }";
    }
    template <typename T, typename V>
    void __print(ostream& out, const map<T, V>& mp) {
        out << "{ ";
        for(auto it = mp.cbegin(); it != mp.cend(); it++) {
            if (it != mp.cbegin())
                out << ", ";
            this->__print(out, *it);
        }
        out << " }";
    }    
    template <typename T, typename V>
    void __print(ostream& out, const unordered_map<T, V>& mp) {
        out << "{ ";
        for(auto it = mp.cbegin(); it != mp.cend(); it++) {
            if (it != mp.cbegin())
                out << ", ";
            this->__print(out, *it);
        }
        out << " }";
    }

private:
    ostream* _ostream_target = &std::cout;

    const uint64_t _CAPACITY = __MAX_OUTPUT_SIZE;
    uint64_t _output_size_counter = 0;
    bool _output_unlimited = false;
    char _space = ' ';

    clock_t _start;
    clock_t _debug_time = 0;

} __printer;

// ------------------------------------------------------------------------------- //

template <typename T>
__Printer& __printArr(const T& a, int n, const char* name, int line) {
    __printer._set_space(-1);
    __printer << "[" << line << "] " << name << ": { ";
    for(int i = 0; i < n; i++) {
        if (i != 0)
            __printer << ", ";
        __printer << "(" << i << ": " << a[i] << ")";
    }
    __printer << " }\n";
    __printer._set_space();
    return __printer;
}

template <typename T>
__Printer& __printMat(const T& a, int n, int m, const char* name, int line) {
    __printer._set_space(-1);
    __printer << "[" << line << "] " << name << ": {\n";
    
    for(int i=0; i<n; i++) {
        __printer << "   " << i << ": ";
        for(int j=0; j<m; j++) {
            if (j != 0)
                __printer << ", ";
            __printer << "(" << j << ": " << a[i][j] << ")";
        }
        __printer << "\n";
    }

    __printer << "}\n";
    __printer._set_space();
    return __printer;
}

template <typename T>
__Printer& __print(const T& t, const char* name, int line) {
    __printer._set_space(-1);
    __printer << "[" << line << "] " << name << ": " << t;
    __printer._set_space();
    return __printer;
}

template <typename T>
__Printer& __println(const T& t, const char* name, int line) {
    __printer._set_space(-1);
    __print(t, name, line);
    __printer << "\n";
    __printer._set_space();
    return __printer;
}

__Printer& __ldb_helper(int line) {
    __printer._set_space(-1);
    __printer << "[" << line << "] ";
    __printer._set_space();
    return __printer;
}


// ------------- API -------------------------------------------------- //

#ifdef HD_DEBUG

#define __printArr(x, n)        __printArr(x, n, #x, __LINE__)
#define __printMat(x, n, m)     __printMat(x, n, m, #x, __LINE__)
#define __print(x)              __print(x, #x, __LINE__)
#define __println(x)            __println(x, #x, __LINE__)

#define __db                    __printer
#define __ldb                   __ldb_helper(__LINE__)
#define __flag                  __ldb << "[Flag!]\n"

#else

struct __Nothing {
    template <typename T>
    __Nothing& operator<<(const T&) { return *this; }
} __nothing;

#define __printArr(x, n)        __nothing
#define __printMat(x, n, m)     __nothing
#define __print(x)              __nothing
#define __println(x)            __nothing

#define __db                    __nothing
#define __ldb                   __nothing
#define __flag                  __nothing

#endif 