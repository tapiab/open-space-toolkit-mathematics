////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           Library/Mathematics/Geometry/2D/Objects/Point.hpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __Library_Mathematics_Geometry_2D_Objects_Point__
#define __Library_Mathematics_Geometry_2D_Objects_Point__

#include <Library/Mathematics/Geometry/2D/Object.hpp>
#include <Library/Mathematics/Objects/Vector.hpp>

#include <Library/Core/Types/Real.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace library
{
namespace math
{
namespace geom
{
namespace d2
{
namespace objects
{

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

using library::core::types::Real ;

using library::math::obj::Vector2d ;
using library::math::geom::d2::Object ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @brief                      Point
///
/// @ref                        https://en.wikipedia.org/wiki/Point_(geometry)

class Point : public Object, public Vector2d
{

    public:

        /// @brief              Constructor
        ///
        /// @code
        ///                     Point point(0.0, 0.0) ;
        /// @endcode
        ///
        /// @param              [in] aFirstCoordinate A first coordinate
        /// @param              [in] aSecondCoordinate A second coordinate

                                Point                                       (   const   Real&                       aFirstCoordinate,
                                                                                const   Real&                       aSecondCoordinate                           ) ;

        /// @brief              Constructor
        ///
        /// @code
        ///                     Point point({ 0.0, 0.0 }) ;
        /// @endcode
        ///
        /// @param              [in] aVector A position vector

                                Point                                       (   const   Vector2d&                   aVector                                     ) ;

        /// @brief              Clone point
        ///
        /// @return             Pointer to cloned point

        virtual Point*          clone                                       ( ) const override ;

        /// @brief              Equal to operator
        ///
        /// @param              [in] aPoint A point
        /// @return             True if points are equal

        bool                    operator ==                                 (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Not equal to operator
        ///
        /// @param              [in] aPoint A point
        /// @return             True if points not are equal

        bool                    operator !=                                 (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Addition operator: translate point along vector
        ///
        /// @code
        ///                     Point(0.0, 0.0) + Vector2d(0.0, 1.0) ; // [0.0, 1.0]
        /// @encode
        ///
        /// @param              [in] aVector A translation vector
        /// @return             A point

        Point                   operator +                                  (   const   Vector2d&                   aVector                                     ) const ;

        /// @brief              Subtraction operator: translate point along opposite vector
        ///
        /// @code
        ///                     Point(0.0, 1.0) - Vector2d(0.0, 1.0) ; // [0.0, 0.0]
        /// @encode
        ///
        /// @param              [in] aVector A translation vector
        /// @return             A point

        Point                   operator -                                  (   const   Vector2d&                   aVector                                     ) const ;

        /// @brief              Subtraction operator: get translation vector between two points
        ///
        /// @code
        ///                     Point(0.0, 1.0) - Point(0.0, 0.0)  ; // [0.0, 1.0]
        /// @encode
        ///
        /// @param              [in] aPoint A point
        /// @return             A translation vector

        Vector2d                operator -                                  (   const   Point&                      aPoint                                      ) const ;

        /// @brief              Output stream operator
        ///
        /// @code
        ///                     std::cout << Point(0.0, 0.0) ;
        /// @endcode
        ///
        /// @param              [in] anOutputStream An output stream
        /// @param              [in] aPoint A point
        /// @return             An output stream

        friend std::ostream&    operator <<                                 (           std::ostream&               anOutputStream,
                                                                                const   Point&                      aPoint                                      ) ;

        /// @brief              Check if point is defined
        ///
        /// @code
        ///                     Point(0.0, 0.0).isDefined() ; // True
        /// @endcode
        ///
        /// @return             True if point is defined

        virtual bool            isDefined                                   ( ) const override ;

        /// @brief              Check if point is near another point
        ///
        /// @code
        ///                     Point(0.0, 0.0).isNear(Point(0.0, 0.0), 1e-15) ; // True
        /// @endcode
        ///
        /// @param              [in] aPoint A point
        /// @param              [in] aTolerance A tolerance
        /// @return             True if point is near another point

        bool                    isNear                                      (   const   Point&                      aPoint,
                                                                                const   Real&                       aTolerance                                  ) const ;

        /// @brief              Translate point
        ///
        /// @param              [in] aTranslation A translation vector

        virtual void            translate                                   (   const   Vector2d&                   aTranslation                                ) override ;

        /// @brief              Constructs an undefined point
        ///
        /// @code
        ///                     Point point = Point::Undefined() ; // Undefined
        /// @endcode
        ///
        /// @return             Undefined point

        static Point            Undefined                                   ( ) ;

        /// @brief              Constructs a point at origin
        ///
        /// @code
        ///                     Point point = Point::Origin() ; // [0.0, 0.0]
        /// @endcode
        ///
        /// @return             Point at origin

        static Point            Origin                                      ( ) ;

} ;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
}
}
}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////