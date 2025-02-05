import React from "react";
import { Link } from "react-router-dom";
const Home = () => {
      return (
            <div className="flex items-center justify-center min-h-screen bg-gray-900 text-white">
                  <div className="text-center">
                        <h1 className="text-4xl font-bold mb-6">
                              Welcome to Our Platform
                        </h1>
                        <div className="flex justify-center space-x-4">
                              <Link
                                    to="/login"
                                    className="px-4 py-2 bg-blue-600 hover:bg-blue-700 text-white rounded transition duration-300"
                              >
                                    Login
                              </Link>
                              <Link
                                    to="/signup"
                                    className="px-4 py-2 bg-green-600 hover:bg-green-700 text-white rounded transition duration-300"
                              >
                                    Signup
                              </Link>
                        </div>
                  </div>
            </div>
      );
};

export default Home;
