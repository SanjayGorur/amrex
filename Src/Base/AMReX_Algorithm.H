#ifndef AMREX_ALGORITHM_H_
#define AMREX_ALGORITHM_H_

#include <algorithm>

#include <AMReX_GpuQualifiers.H>
#include <AMReX_Extension.H>
#include <AMReX_Dim3.H>

namespace amrex
{
    template <class T>
    AMREX_GPU_HOST_DEVICE
    AMREX_FORCE_INLINE constexpr const T& min (const T& a, const T& b) noexcept
    {
        return (b < a) ? b : a;
    }

    template <class T, class ... Ts>
    AMREX_GPU_HOST_DEVICE
    AMREX_FORCE_INLINE constexpr const T& min (const T& a, const T& b, const Ts& ... c) noexcept
    {
        return min(min(a,b),c...);
    }

    template <class T>
    AMREX_GPU_HOST_DEVICE
    AMREX_FORCE_INLINE constexpr const T& max (const T& a, const T& b) noexcept
    {
        return (a < b) ? b : a;
    }

    template <class T, class ... Ts>
    AMREX_GPU_HOST_DEVICE
    AMREX_FORCE_INLINE constexpr const T& max (const T& a, const T& b, const Ts& ... c) noexcept
    {
        return max(max(a,b),c...);
    }

    AMREX_GPU_HOST_DEVICE AMREX_FORCE_INLINE constexpr
    Dim3 elemwiseMin (Dim3 const& a, Dim3 const& b) noexcept {
        return Dim3{amrex::min(a.x,b.x),amrex::min(a.y,b.y),amrex::min(a.z,b.z)};
    }

    AMREX_GPU_HOST_DEVICE AMREX_FORCE_INLINE constexpr
    Dim3 elemwiseMax (Dim3 const& a, Dim3 const& b) noexcept {
        return Dim3{amrex::max(a.x,b.x),amrex::max(a.y,b.y),amrex::max(a.z,b.z)};
    }

    template<typename T>
    AMREX_GPU_HOST_DEVICE AMREX_FORCE_INLINE
    void Swap (T& t1, T& t2) noexcept
    {
        T temp = std::move(t1);
        t1 = std::move(t2);
        t2 = std::move(temp);
    }

    template <typename T>
    AMREX_GPU_HOST_DEVICE AMREX_FORCE_INLINE
    constexpr const T& Clamp (const T& v, const T& lo, const T& hi)
    {
        return (v < lo) ? lo : (hi < v) ? hi : v;
    }
}

#endif
