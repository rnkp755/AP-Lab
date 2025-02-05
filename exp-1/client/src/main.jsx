import React from "react";
import ReactDOM from "react-dom/client";
import {
      RouterProvider,
      Route,
      createBrowserRouter,
      createRoutesFromElements,
} from "react-router-dom";
import "./index.css";
import Home from "./Home.jsx";
import Signup from "./Signup.jsx";
import Login from "./Login.jsx";
const router = createBrowserRouter(
      createRoutesFromElements(
            <React.Fragment>
                  <Route path="/" element={<Home />} />
                  <Route path="/signup" element={<Signup />} />
                  <Route path="/login" element={<Login />} />
            </React.Fragment>
      )
);

ReactDOM.createRoot(document.getElementById("root")).render(
      <React.StrictMode>
            <RouterProvider router={router} />
      </React.StrictMode>
);
