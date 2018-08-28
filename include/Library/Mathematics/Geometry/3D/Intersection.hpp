////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/3D/Intersection.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Mathematics_Geometry_3D_Intersection__
#define __Library_Mathematics_Geometry_3D_Intersection__

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Library/Mathematics/Geometry/3D/Objects/Ellipsoid.hpp>
#include <Library/Mathematics/Geometry/3D/Objects/Sphere.hpp>
#include <Library/Mathematics/Geometry/3D/Objects/Segment.hpp>
#include <Library/Mathematics/Geometry/3D/Objects/Point.hpp>
#include <Library/Mathematics/Geometry/3D/Object.hpp>

#include <Library/Core/Containers/Array.hpp>
#include <Library/Core/Types/Unique.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace math
{
namespace geom
{
namespace d3
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Unique ;
using library::core::ctnr::Array ;

using library::math::geom::d3::Object ;
using library::math::geom::d3::objects::Point ;
using library::math::geom::d3::objects::Segment ;
using library::math::geom::d3::objects::Sphere ;
using library::math::geom::d3::objects::Ellipsoid ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      3D intersection

class Intersection
{

    public:

        enum class Type
        {

            Undefined,
            Empty,
            Point,
            PointSet,
            Line,
            Ray,
            Segment,
            Plane,
            Sphere,
            Ellipsoid,
            Complex

        } ;

        /// @brief              Constructor
        ///
        /// @param              [in] anObjectArray An array of objects

                                Intersection                                (   const   Array<Unique<Object>>&      anObjectArray                               ) ;

        /// @brief              Copy constructor
        ///
        /// @param              [in] anIntersection An intersection

                                Intersection                                (   const   Intersection&               anIntersection                              ) ;

        /// @brief              Destructor

                                ~Intersection                               ( ) ;

        /// @brief              Copy assignment operator
        ///
        /// @param              [in] anIntersection An intersection
        /// @return             Reference to intersection

        Intersection&           operator =                                  (   const   Intersection&               anIntersection                              ) ;

        /// @brief              Equal to operator
        ///
        /// @param              [in] anIntersection An intersection
        /// @return             True if intersections are equal

        bool                    operator ==                                 (   const   Intersection&               anIntersection                              ) const ;

        /// @brief              Not equal to operator
        ///
        /// @param              [in] anIntersection An intersection
        /// @return             True if intersections not are equal

        bool                    operator !=                                 (   const   Intersection&               anIntersection                              ) const ;

        /// @brief              Check if intersection is defined
        ///
        /// @return             True if intersection is defined

        bool                    isDefined                                   ( ) const ;

        /// @brief              Check if intersection is empty
        ///
        /// @return             True if intersection is empty

        bool                    isEmpty                                     ( ) const ;

        /// @brief              Get intersection type
        ///
        /// @return             Intersection type

        Intersection::Type      getType                                     ( ) const ;

        /// @brief              Constructs an undefined intersection
        ///
        /// @code
        ///                     Intersection intersection = Intersection::Undefined() ; // Undefined
        /// @endcode
        ///
        /// @return             Undefined intersection

        static Intersection     Undefined                                   ( ) ;

        /// @brief              Constructs an empty intersection
        ///
        /// @code
        ///                     Intersection intersection = Intersection::Empty() ;
        /// @endcode
        ///
        /// @return             Empty intersection

        static Intersection     Empty                                       ( ) ;

    private:

        Intersection::Type      type_ ;

        Array<Unique<Object>>   objects_ ;

        static Intersection::Type TypeFromObjects                           (   const   Array<Unique<Object>>&      anObjectArray                               ) ;

        static Intersection::Type TypeFromObject                            (   const   Unique<Object>&             anObjectUPtr                                ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////