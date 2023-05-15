/// Apache License 2.0

#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Intersection.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Objects/Ellipsoid.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Objects/Pyramid.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Transformation.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Transformations/Rotations/RotationVector.hpp>

#include <Global.test.hpp>

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, Constructor)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_NO_THROW(Pyramid(base, apex));
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, Clone)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_NO_THROW(const Pyramid* pyramidPtr = Pyramid(base, apex).clone(); delete pyramidPtr;);
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, EqualToOperator)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_TRUE(Pyramid(base, apex) == Pyramid(base, apex));
    }

    {

        // [TBI] Implement similarities

    }

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_FALSE(Pyramid(base, apex) == Pyramid::Undefined());
        EXPECT_FALSE(Pyramid::Undefined() == Pyramid(base, apex));
        EXPECT_FALSE(Pyramid::Undefined() == Pyramid::Undefined());
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, NotEqualToOperator)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_FALSE(Pyramid(base, apex) != Pyramid(base, apex));
    }

    {

        // [TBI] Implement similarities

    }

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_TRUE(Pyramid(base, apex) != Pyramid::Undefined());
        EXPECT_TRUE(Pyramid::Undefined() != Pyramid(base, apex));
        EXPECT_TRUE(Pyramid::Undefined() != Pyramid::Undefined());
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, StreamOperator)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        testing::internal::CaptureStdout();

        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_NO_THROW(std::cout << Pyramid(base, apex) << std::endl);

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty());
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, IsDefined)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_TRUE(Pyramid(base, apex).isDefined());
    }

    {
        EXPECT_FALSE(Pyramid::Undefined().isDefined());
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, Intersects_Ellipsoid)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Ellipsoid;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{-0.1, -0.1}, {+0.1, -0.1}, {+0.1, +0.1}, {-0.1, +0.1}}},
            {0.0, 0.0, 1.0},
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 0.0};

        const Pyramid pyramid = {base, apex};

        const Ellipsoid ellipsoid = {{0.0, 0.0, 10.0}, 5.0, 5.0, 5.0};

        EXPECT_TRUE(pyramid.intersects(ellipsoid));
    }

    {
        EXPECT_ANY_THROW(Pyramid::Undefined().intersects(Ellipsoid::Undefined()));
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, Contains_Point)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{-0.1, -0.1}, {+0.1, -0.1}, {+0.1, +0.1}, {-0.1, +0.1}}},
            {0.0, 0.0, 1.0},
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 0.0};

        const Pyramid pyramid = {base, apex};

        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, 1.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, 2.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, 3.0}));

        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, -1.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, -2.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, -3.0}));

        EXPECT_FALSE(pyramid.contains(Point {+1.0, 0.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {-1.0, 0.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {0.0, +1.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, -1.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {2.0, 2.0, 1.0}));
    }

    {
        const Polygon base = {
            {{{-0.1, -0.1}, {+0.1, -0.1}, {+0.1, +0.1}, {-0.1, +0.1}}},
            {0.0, 0.0, -1.0},
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 0.0};

        const Pyramid pyramid = {base, apex};

        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, -1.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, -2.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, -3.0}));

        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, 1.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, 2.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, 3.0}));

        EXPECT_FALSE(pyramid.contains(Point {+1.0, 0.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {-1.0, 0.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {0.0, +1.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, -1.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {2.0, 2.0, -1.0}));
    }

    {
        const Polygon base = {
            {{{-0.1, -0.1}, {+0.1, -0.1}, {+0.1, +0.1}, {-0.1, +0.1}}},
            {0.0, 2.0, 0.0},
            {1.0, 0.0, 0.0},
            {0.0, 0.0, -1.0}};
        const Point apex = {0.0, 1.0, 0.0};

        const Pyramid pyramid = {base, apex};

        EXPECT_TRUE(pyramid.contains(Point {0.0, 1.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 2.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 3.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {0.0, 4.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, -1.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, -2.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, -2.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {+1.0, 0.0, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {-1.0, 0.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, +1.0}));
        EXPECT_FALSE(pyramid.contains(Point {0.0, 0.0, -1.0}));

        EXPECT_FALSE(pyramid.contains(Point {1.0, 1.0, 1.0}));
    }

    {
        const Polygon base = {
            {{{-1.0, -1.0}, {+1.0, -1.0}, {+1.0, +1.0}, {-1.0, +1.0}}},
            {2.0, 2.0, 0.0},
            {0.0, 0.0, -1.0},
            {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 0.0};

        const Pyramid pyramid = {base, apex};

        EXPECT_TRUE(pyramid.contains(Point {0.0, 0.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {2.0, 2.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {2.0, 1.0, 0.0}));
        EXPECT_TRUE(pyramid.contains(Point {2.0, 3.0, 0.0}));

        EXPECT_FALSE(pyramid.contains(Point {2.0, 0.5, 0.0}));
        EXPECT_FALSE(pyramid.contains(Point {1.0, 2.0, 0.0}));
    }

    {
        EXPECT_ANY_THROW(Pyramid::Undefined().contains(Point::Undefined()));
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, Contains_PointSet)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::PointSet;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{-0.1, -0.1}, {+0.1, -0.1}, {+0.1, +0.1}, {-0.1, +0.1}}},
            {0.0, 0.0, 1.0},
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 0.0};

        const Pyramid pyramid = {base, apex};

        EXPECT_TRUE(pyramid.contains(PointSet({{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}})));
        EXPECT_TRUE(pyramid.contains(PointSet({{0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}})));

        EXPECT_FALSE(pyramid.contains(PointSet({{0.0, 0.0, 0.0}, {0.0, 0.0, -1.0}})));
        EXPECT_FALSE(pyramid.contains(PointSet({{0.0, 0.0, 0.0}, {0.0, 0.0, -2.0}})));
        EXPECT_FALSE(pyramid.contains(PointSet({{0.0, 0.0, 0.0}, {0.0, 0.0, -3.0}})));
    }

    {
        EXPECT_ANY_THROW(Pyramid::Undefined().contains(PointSet::Empty()));
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, Contains_Segment)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Segment;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{-0.1, -0.1}, {+0.1, -0.1}, {+0.1, +0.1}, {-0.1, +0.1}}},
            {0.0, 0.0, 1.0},
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 0.0};

        const Pyramid pyramid = {base, apex};

        EXPECT_TRUE(pyramid.contains(Segment {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}}));
        EXPECT_TRUE(pyramid.contains(Segment {{0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}));

        EXPECT_FALSE(pyramid.contains(Segment {{0.0, 0.0, 0.0}, {0.0, 0.0, -1.0}}));
        EXPECT_FALSE(pyramid.contains(Segment {{0.0, 0.0, 0.0}, {0.0, 0.0, -2.0}}));
        EXPECT_FALSE(pyramid.contains(Segment {{0.0, 0.0, 0.0}, {0.0, 0.0, -3.0}}));
    }

    {
        EXPECT_ANY_THROW(Pyramid::Undefined().contains(Segment::Undefined()));
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, GetBase)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_EQ(base, Pyramid(base, apex).getBase());
    }

    {
        EXPECT_ANY_THROW(Pyramid::Undefined().getBase());
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, GetApex)
{
    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_EQ(apex, Pyramid(base, apex).getApex());
    }

    {
        EXPECT_ANY_THROW(Pyramid::Undefined().getApex());
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, IntersectionWith_Ellipsoid)
{
    using ostk::core::types::Real;

    using ostk::math::obj::Vector3d;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::LineString;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Ellipsoid;
    using ostk::math::geom::d3::objects::Pyramid;
    using ostk::math::geom::d3::Intersection;

    {
        const Polygon base = {
            {{{-0.1, -0.1}, {+0.1, -0.1}, {+0.1, +0.1}, {-0.1, +0.1}}},
            {0.0, 0.0, 1.0},
            {1.0, 0.0, 0.0},
            {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 0.0};

        const Pyramid pyramid = {base, apex};

        const Ellipsoid ellipsoid = {{0.0, 0.0, 10.0}, 5.0, 5.0, 5.0};

        const Intersection intersection = pyramid.intersectionWith(ellipsoid, true, 8);

        EXPECT_TRUE(intersection.isDefined());
        EXPECT_FALSE(intersection.isEmpty());
        EXPECT_TRUE(intersection.accessComposite().is<LineString>());

        const LineString intersectionLineString = intersection.accessComposite().as<LineString>();

        EXPECT_EQ(8, intersectionLineString.getPointCount());

        const LineString referenceLineString = {
            {{-0.505129425743498, -0.505129425743498, 5.05129425743498},
             {-0.505129425743498, 0.505129425743499, 5.05129425743498},
             {-0.505129425743498, 0.505129425743498, 5.05129425743498},
             {0.505129425743499, 0.505129425743498, 5.05129425743498},
             {0.505129425743498, 0.505129425743498, 5.05129425743498},
             {0.505129425743498, -0.505129425743499, 5.05129425743498},
             {0.505129425743498, -0.505129425743498, 5.05129425743498},
             {-0.505129425743499, -0.505129425743498, 5.05129425743498}}};

        EXPECT_TRUE(intersectionLineString.isNear(referenceLineString, 1e-10));
    }

    {
        EXPECT_ANY_THROW(Pyramid::Undefined().intersectionWith(Ellipsoid::Undefined()));
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, ApplyTransformation)
{
    using ostk::core::types::Real;

    using ostk::math::obj::Vector3d;
    using ostk::math::geom::Angle;
    using ostk::math::geom::d3::objects::Point;
    using ostk::math::geom::d3::objects::Polygon;
    using ostk::math::geom::d3::objects::Pyramid;
    using ostk::math::geom::d3::Transformation;
    using ostk::math::geom::d3::trf::rot::RotationVector;

    // Translation

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        Pyramid pyramid = {base, apex};

        pyramid.applyTransformation(Transformation::Translation({4.0, 5.0, 6.0}));

        EXPECT_EQ(
            Pyramid(
                {{{{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}},
                  {4.0, 5.0, 6.0},
                  {1.0, 0.0, 0.0},
                  {0.0, 1.0, 0.0}},
                 {4.0, 5.0, 7.0}}
            ),
            pyramid
        );
    }

    // Rotation

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 2.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}};
        const Point apex = {0.0, 1.0, 0.0};

        Pyramid pyramid = {base, apex};

        pyramid.applyTransformation(Transformation::Rotation(RotationVector({1.0, 0.0, 0.0}, Angle::Degrees(90.0))));

        const Polygon referenceBase = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 2.0}, {0.0, -1.0, 0.0}, {1.0, 0.0, 0.0}};
        const Point referenceApex = {0.0, 0.0, 1.0};

        const Pyramid referencePyramid = {referenceBase, referenceApex};

        EXPECT_TRUE(pyramid.getBase().isNear(referencePyramid.getBase(), Real::Epsilon()))
            << referencePyramid.getBase() << pyramid.getBase();
        EXPECT_TRUE(pyramid.getApex().isNear(referencePyramid.getApex(), Real::Epsilon()))
            << referencePyramid.getApex().toString() << pyramid.getApex().toString();
    }

    {
        const Polygon base = {
            {{{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}}}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}};
        const Point apex = {0.0, 0.0, 1.0};

        EXPECT_ANY_THROW(Pyramid::Undefined().applyTransformation(Transformation::Undefined()));
        EXPECT_ANY_THROW(Pyramid::Undefined().applyTransformation(Transformation::Identity()));
        EXPECT_ANY_THROW(Pyramid(base, apex).applyTransformation(Transformation::Undefined()));
    }
}

TEST(OpenSpaceToolkit_Mathematics_Geometry_3D_Objects_Pyramid, Undefined)
{
    using ostk::math::geom::d3::objects::Pyramid;

    {
        EXPECT_NO_THROW(Pyramid::Undefined());
        EXPECT_FALSE(Pyramid::Undefined().isDefined());
    }
}
