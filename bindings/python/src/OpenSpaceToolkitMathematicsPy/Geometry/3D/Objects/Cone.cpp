////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Mathematics
/// @file           bindings/python/src/OpenSpaceToolkitMathematicsPy/Geometry/3D/Objects/Cone.cpp
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Intersection.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Objects/Cone.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline void                     OpenSpaceToolkitMathematicsPy_Geometry_3D_Objects_Cone (        pybind11::module&   aModule                                     )
{

    using namespace pybind11 ;

    using ostk::core::types::Size ;
    using ostk::core::types::Real ;

    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::Angle ;
    using ostk::math::geom::d3::Object ;
    using ostk::math::geom::d3::objects::Point ;
    using ostk::math::geom::d3::objects::PointSet ;
    using ostk::math::geom::d3::objects::Line ;
    using ostk::math::geom::d3::objects::Ray ;
    using ostk::math::geom::d3::objects::Segment ;
    using ostk::math::geom::d3::objects::Plane ;
    using ostk::math::geom::d3::objects::Polygon ;
    using ostk::math::geom::d3::objects::Sphere ;
    using ostk::math::geom::d3::objects::Ellipsoid ;
    using ostk::math::geom::d3::objects::Cone ;
    using ostk::math::geom::d3::Intersection ;

    class_<Cone, Object>(aModule, "Cone")

        .def(init<const Point&, const Vector3d&, const Angle&>())

        .def(self == self)
        .def(self != self)

        .def("__str__", &(shiftToString<Cone>))
        .def("__repr__", &(shiftToString<Cone>))

        .def("is_defined", &Cone::isDefined)
        .def("intersects", overload_cast<const Sphere&, const Size>(&Cone::intersects, const_), arg("sphere"), arg("discretization_level") = 40)
        .def("intersects", overload_cast<const Ellipsoid&, const Size>(&Cone::intersects, const_), arg("ellipsoid"), arg("discretization_level") = 40)
        .def("intersects_ellipsoid", +[] (const Cone& aCone, const Ellipsoid& anEllipsoid) -> bool { return aCone.intersects(anEllipsoid) ; }) // TBR
        .def("intersects_ellipsoid", +[] (const Cone& aCone, const Ellipsoid& anEllipsoid, const Size aDiscretizationLevel) -> bool { return aCone.intersects(anEllipsoid, aDiscretizationLevel) ; }) // TBR

        .def("get_apex", &Cone::getApex)
        .def("get_axis", &Cone::getAxis)
        .def("get_angle", &Cone::getAngle)
        .def("get_rays_of_lateral_surface", &Cone::getRaysOfLateralSurface)
        .def("intersection_with", overload_cast<const Sphere&, const bool, const Size>(&Cone::intersectionWith, const_), arg("sphere"), arg("only_in_sight") = false, arg("discretization_level") = 40)
        .def("intersection_with", overload_cast<const Ellipsoid&, const bool, const Size>(&Cone::intersectionWith, const_), arg("ellipsoid"), arg("only_in_sight") = false, arg("discretization_level") = 40)
        .def("intersection_with_ellipsoid", +[] (const Cone& aCone, const Ellipsoid& anEllipsoid) -> Intersection { return aCone.intersectionWith(anEllipsoid) ; }) // TBR
        .def("intersection_with_ellipsoid", +[] (const Cone& aCone, const Ellipsoid& anEllipsoid, const bool onlyInSight) -> Intersection { return aCone.intersectionWith(anEllipsoid, onlyInSight) ; }) // TBR
        .def("intersection_with_ellipsoid", +[] (const Cone& aCone, const Ellipsoid& anEllipsoid, const bool onlyInSight, const Size aDiscretizationLevel) -> Intersection { return aCone.intersectionWith(anEllipsoid, onlyInSight, aDiscretizationLevel) ; }) // TBR
        .def("apply_transformation", &Cone::applyTransformation)

        .def_static("undefined", &Cone::Undefined)
    ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
